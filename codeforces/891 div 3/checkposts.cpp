#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int ptr(int sc, vector<int> &par)
{
    if (sc == par[sc])
        return sc;
    else
        return par[sc] = ptr(par[sc], par);
}
void idact(int sc, vector<int> &parent, int par, vector<int> &id)
{
    int pt = par;
    while (pt != sc)
    {
        id[pt] = id[sc];
        pt = parent[pt];
    }
}
void dfs(int sc, int par, vector<bool> &vis, vector<int> &parent, vector<vector<int>> &v, vector<int> &id)
{
    if (vis[sc])
    {
        idact(sc, parent, par, id);
        return;
    }
    vis[sc] = true;
    parent[sc] = par;
    for (auto &child : v[sc])
        dfs(child, sc, vis, parent, v, id);
}

void normdfs(int sc, vector<vector<int>> &v, vector<bool> &vis, vector<int> &ret)
{
    if (vis[sc])
        return;
    vis[sc] = true;
    for (auto &child : v[sc])

        normdfs(child, v, vis, ret);
    ret.push_back(sc);
}

vector<int> topo(vector<vector<int>> &v, int n)
{
    vector<int> ret;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
        normdfs(i, v, vis, ret);
    reverse(ret.begin(), ret.end());
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> cost(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    vector<int> id(n + 1);
    for (int i = 0; i < n + 1; i++)
        id[i] = i;
    int m;
    cin >> m;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        auto it = lower_bound(v[x].begin(), v[x].end(), y);
        if ((it == v[x].end()) || (*it != y))
            v[x].push_back(y);
    }
    vector<int> tp = topo(v, n);
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1);
    for (int i = 0; i < tp.size(); i++)
        if (!vis[tp[i]])
        {
            dfs(tp[i], 0, vis, parent, v, id);
        }
    for (int i = 1; i <= n; i++)
        id[i] = ptr(i, id);
    map<int, map<int, int>> mp;
    LL cst = 0;
    LL ways = 1;
    const LL mod = 1e9 + 7;
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
    for (int i = 1; i <= n; i++)
        cout << i << " " << id[i] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}