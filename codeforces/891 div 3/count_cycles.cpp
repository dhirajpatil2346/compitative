#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
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
        cout << "inside " << par << "--> " << sc << endl;
        if (id[sc] == sc)
            idact(sc, parent, par, id);
        return;
    }
    cout << par << "--> " << sc << endl;
    vis[sc] = true;
    parent[sc] = par;
    for (auto &child : v[sc])
        if (id[child] == child)
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
void dfu(int sc, vector<vector<int>> &v, vector<bool> &vis, vector<int> &ret)
{
    if (vis[sc])
    {
        ret[sc]++;
        return;
    }
    vis[sc] = true;
    for (auto &child : v[sc])
        dfu(child, v, vis, ret);
}
vector<int> count(vector<vector<int>> &v, int n)
{
    vector<int> ret(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
        dfu(i, v, vis, ret);
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
    vector<int> freq = count(v, n);
    for (int i = 1; i <= n; i++)
        cout << i << " " << freq[i] << endl;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    solve();
    return 0;
}