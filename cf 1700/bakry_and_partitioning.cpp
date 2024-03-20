#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int dfs(int sc, vector<vector<int>> &graph, int &c, int &x, vector<int> &v, vector<bool> &vis)
{
    if (vis[sc])
        return 0;
    vis[sc] = true;
    int ret = v[sc];
    for (auto &val : graph[sc])
        if (!vis[val])
            ret ^= dfs(val, graph, c, x, v, vis);
    if (ret == x)
        c++, ret = 0;
    // cout << sc << " " << ret << endl;
    return ret;
}
bool solve()
{
    int n, k;
    cin >> n >> k;
    k--;
    int x = 0;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        x ^= v[i];
    }
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if (x == 0)
        return true;
    int minreq = 2;
    if (minreq > k)
        return false;
    int c = 0;
    vector<bool> vis(n + 1, false);
    dfs(1, graph, c, x, v, vis);
    // cout << x << " " << c << endl;
    return c >= 3;
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}