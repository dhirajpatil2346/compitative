#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;

vector<LL> prefix_function(string s)
{
    LL n = (LL)s.length();
    vector<LL> pi(n);
    for (LL i = 1; i < n; i++)
    {
        LL j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

LL bin(LL a, LL p)
{
    if (p == 0)
        return 1;
    LL res = bin(a, p / 2ll);
    res = (res * res) % mod;
    if (p & 1ll)
        res = (res * a) % mod;
    return res;
}

LL mmi(LL a)
{
    return bin(a, mod - 2);
}

const LL sz = 1e7 + 5;
vector<LL> primes;
void sieve()
{
    vector<bool> isp(sz, true);
    isp[0] = false, isp[1] = false;
    for (LL i = 2; i * i <= sz; i++)
        if (isp[i])
            for (LL j = i * i; j < sz; j += i)
                isp[j] = false;
    for (int i = 2; i < sz; i++)
        if (isp[i])
            primes.push_back(i);
}

void solve()
{
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n), b(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    vector<LL> one, two;
    for (int i = 0; i < n; i++)
        if (b[i] == 1)
            one.push_back(a[i]);
        else
            two.push_back(a[i]);
    sort(one.rbegin(), one.rend());
    sort(two.rbegin(), two.rend());
    for (int i = 1; i < one.size(); i++)
        one[i] += one[i - 1];
    for (int i = 1; i < two.size(); i++)
        two[i] += two[i - 1];
    LL ans = LLONG_MAX;
    LL req, ind;
    req = m;
    ind = lower_bound(one.begin(), one.end(), req) - one.begin();
    if (ind != one.size())
        ans = ind + 1;
    for (LL i = 0; i < two.size(); i++)
    {
        req = m - two[i];
        ind = -1;
        if (req > 0)
        {
            ind = lower_bound(one.begin(), one.end(), req) - one.begin();
        }
        if (ind == one.size())
            continue;
        ans = min(ans, (i + 1) * 2 + ind + 1);
    }
    if (ans == LLONG_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}