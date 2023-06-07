#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void dfs(int sc, int cp, vector<vector<int>> &v, vector<int> &power)
{
    if (cp < 0)
        return;
    if (power[sc] >= cp)
        return;
    power[sc] = cp;
    for (auto &child : v[sc])
    {
        cout << sc << " " << child << " " << cp - 1 << endl;
        dfs(child, cp - 1, v, power);
    }
}
void solve()
{
    LL n, m, k;
    cin >> n >> m >> k;
    vector<int> nodes(k), dist(k);
    for (auto &val : nodes)
        cin >> val;
    for (auto &val : dist)
        cin >> val;
    vector<vector<int>> v(n + 1);
    vector<int> power(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << x << " " << y << endl;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " --> ";
        for (auto &val : v[i])
            cout << val << " ";
        cout << endl;
    }
    for (int i = 0; i < k; i++)
    {
        // cout << "  " << nodes[i] << " " << dist[i] << endl;
        dfs(nodes[i], dist[i], v, power);
    }
    bool g = true;
    for (int i = 1; i <= n; i++)
        if (power[i] == -1)
            g = false;
    if (g)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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