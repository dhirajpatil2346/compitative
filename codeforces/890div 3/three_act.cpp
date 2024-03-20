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
    LL n;
    cin >> n;
    vector<pair<LL, LL>> a, b, c;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back({x, i});
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back({x, i});
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        c.push_back({x, i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    while (a.size() > 3)
        a.pop_back();
    while (b.size() > 3)
        b.pop_back();
    while (c.size() > 3)
        c.pop_back();
    LL ans = 0;
    for (auto &p1 : a)
        for (auto &p2 : b)
            for (auto &p3 : c)
            {
                set<LL> s = {p1.second, p2.second, p3.second};
                if (s.size() != 3)
                    continue;
                ans = max(ans, p1.first + p2.first + p3.first);
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