#include <bits/stdc++.h>
using namespace std;
int cost = INT_MAX;

void dfs(int sr, int sc, int row, int col, vector<vector<bool>> vis, vector<vector<int>> &c, vector<vector<int>> &e, int cost_c, int energy)
{
    if (sr < 0 || sr > row || sc < 0 || sc > col)
    {
        return;
    }
    if (sr == row && sc == col)
    {
        cost = min(cost, cost_c);
        return;
    }
    if (energy < 0)
    {
        return;
    }
    if (vis[sr][sc])
    {
        return;
    }
    cost_c += c[sr][sc];
    energy += e[sr][sc];
    vis[sr][sc] = true;
    dfs(sr - 1, sc, row, col, vis, c, e, cost_c, energy + 1);
    dfs(sr + 1, sc, row, col, vis, c, e, cost_c, energy - 1);
    dfs(sr, sc + 1, row, col, vis, c, e, cost_c, energy - 1);
    dfs(sr, sc - 1, row, col, vis, c, e, cost_c, energy + 1);
}
int main()
{
    cost = INT_MAX;
    int n, m, k;
    cin >> n >> m >> k;
    int row = n, col = m;
    vector<vector<bool>> vis(n);
    vector<vector<int>> c(n);
    vector<vector<int>> v(n);
    vector<vector<int>> e(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i].push_back(false);
            e[i].push_back(0);
            v[i].push_back(0);
            c[i].push_back(0);
        }
    }
    for (int i = 0; i < k; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        c[x][y] = a, e[x][y] = b;
    }
    // dfs run  :: arguments vis (normal) &c &e row col
    dfs(0, 0, n - 1, m - 1, vis, c, e, 0, 0);
    cout << cost << endl;
    return 0;
}