#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int sr, int sc, int n, int m, vector<string> &v, vector<vector<bool>> &vis)
{
    if (sr < 0 || sr >= n || sc < 0 || sc >= m || vis[sr][sc] || v[sr][sc] == '#')
    {
        return;
    }
    // cout << sr << " " << sc << endl;
    vis[sr][sc] = true;
    dfs(sr + 1, sc, n, m, v, vis);
    dfs(sr - 1, sc, n, m, v, vis);
    dfs(sr, sc + 1, n, m, v, vis);
    dfs(sr, sc - 1, n, m, v, vis);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    vector<vector<bool>> vis(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i].push_back(false);
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] || v[i][j] == '#')
            {
                continue;
            }
            // cout << i << "  " << j<<"   "<<v[i][j] << endl;
            c++;
            dfs(i, j, n, m, v, vis);
        }
    }
    cout << c << endl;
    return 0;
}