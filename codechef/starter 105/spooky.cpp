#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

void dfs(int sc, map<LL, LL> &m, vector<bool> &vis, vector<vector<int>> &v, vector<LL> &power)
{
    if (vis[sc])
        return;
    m[power[sc]]++;
    vis[sc] = true;
    for (auto &child : v[sc])
        dfs(child, m, vis, v, power);
}
const LL mod = 1e9 + 7;
const LL sz = 2e5 + 10;
vector<LL> fact(sz, 1);
void sieve()
{
    for (LL i = 1; i < sz; i++)
    {
        fact[i] = i;
        fact[i] = (fact[i - 1] * fact[i]) % mod;
    }
}
LL bin(LL a, LL p)
{
    if (p == 0)
        return 1ll;
    LL res = bin(a, p / 2ll);
    res = (res * res) % mod;
    if (p & 1ll)
        res = (res * a) % mod;
    return res;
}
LL mmi(LL n)
{
    return bin(n, mod - 2ll);
}

void solve()
{
    LL n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    set<LL> ans;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        ans.insert(x);
        ans.insert(y);
    }
    LL currs = fact[n];
    // cout << currs << endl;
    vector<LL> power(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> power[i];
    vector<bool> vis(n + 1, false);
    for (auto &val : ans)
    {
        map<LL, LL> curr;
        dfs(val, curr, vis, v, power);
        currs = (currs * mmi(fact[curr.size()])) % mod;
        // cout << curr.size() << " " << currs << endl;
    }
    cout << currs << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}