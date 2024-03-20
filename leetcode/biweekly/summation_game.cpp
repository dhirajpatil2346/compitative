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
    LL n, k, x;
    cin >> n >> k >> x;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    vector<LL> neg = v;
    for (auto &val : neg)
        val *= (-1ll);
    for (int i = 1; i < n; i++)
        neg[i] += neg[i - 1], v[i] += v[i - 1];
    LL ans = -1e18;
    if (k >= n)
        ans = 0;
    for (int r = 0, ind = n - 1; r <= k && ind >= 0; r++, ind--)
    {
        LL sum = v[ind];
        LL part = neg[ind];
        if ((ind - x) >= 0)
            part -= neg[ind - x];
        part *= (2ll);
        // cout << r << " " << sum << " " << part << endl;
        sum += part;
        ans = max(ans, sum);
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