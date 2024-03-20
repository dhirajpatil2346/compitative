#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void dfs(int sc, vector<vector<int>> &v, vector<int> &ret, vector<bool> &vis)
{
    if (vis[sc])
        return;
    vis[sc] = true;
    for (auto &child : v[sc])
        dfs(child, v, ret, vis);
    ret.push_back(sc);
}
vector<int> topo(vector<vector<int>> &v, int n)
{
    vector<bool> vis(n + 1, false);
    vector<int> ret;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, v, ret, vis);
    reverse(ret.begin(), ret.end());
    return ret;
}

void dfu(int sc, vector<vector<int>> &v, vector<int> &ret, vector<bool> &vis)
{
    if (vis[sc])
        return;
    ret.push_back(sc);
    vis[sc] = true;
    for (auto &child : v[sc])
        dfu(child, v, ret, vis);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1), vrev(n + 1);
    vector<LL> cost(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        vrev[y].push_back(x);
    }
    vector<int> tp = topo(v, n);
    vector<int> id(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        vector<int> ret;
        if (!vis[tp[i]])
            dfu(tp[i], vrev, ret, vis);
        for (auto &val : ret)
            id[val] = i;
    }
    LL cst = 0;
    LL ways = 1;
    const LL mod = 1e9 + 7;
    map<int, map<LL, LL>> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[id[i]][cost[i]]++;
    }
    for (auto &val : mp)
    {
        cst = cst + (1ll * (*(val.second.begin())).first);
        ways = (ways * 1ll * (*(val.second.begin())).second) % mod;
    }
    cout << cst << " " << ways << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}