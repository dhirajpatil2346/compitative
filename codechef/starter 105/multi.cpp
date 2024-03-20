#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
const int sz = 1e6 + 5;
vector<int> fact(sz);
void sieve()
{
    for (int i = 0; i < sz; i++)
        fact[i] = i;
    for (int i = 2; i * i <= sz; i++)
        if (fact[i] == i)
            for (int j = i * i; j < sz; j += i)
                fact[j] = i;
}

void gen(LL curr, map<LL, LL> &m, LL last, set<LL> &s)
{
    if (m.upper_bound(last) == m.end())
    {
        s.insert(curr);
        return;
    }
    auto it = m.upper_bound(last);
    int f = it->first;
    last = f;
    gen(curr, m, last, s);
    for (int i = 0; i < it->second; i++)
    {
        curr *= it->first;
        gen(curr, m, last, s);
    }
}

void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    unordered_map<LL, LL> m;
    m[0] = 1;
    for (LL i = 0; i < n; i++)
    {
        map<LL, LL> fct;
        while (v[i] > 1)
        {
            fct[fact[v[i]]]++;
            v[i] /= fact[v[i]];
        }
        set<LL> s;
        gen(1ll, fct, 1ll, s);
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            if (m.find((*it) - 1) == m.end())
                continue;
            m[*it] = (m[*it] + (m[(*it) - 1])) % mod;
        }
        // for (auto &val : m)
        //     cout << val.first << " " << val.second << endl;
        // cout << endl;
    }
    LL ans = 0;
    m.erase(0);
    for (auto &val : m)
        ans = (ans + val.second) % mod;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}