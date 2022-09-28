#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool got = false;
vector<char> ans;
void dfs(int sr, int sc, int destr, int destc, int n, int m, vector<string> v, vector<vector<bool>> &vis, vector<char> path, char move)
{
    if (sr < 0 || sr >= n || sc < 0 || sc >= m || vis[sr][sc] || v[sr][sc] == '#')
    {
        return;
    }
    vis[sr][sc] = true;
    path.push_back(move);

    if (sr == destr && sc == destc)
    {
        if (ans.size() == 0)
        {
            ans = path;
            return;
        }
        else if (path.size() < ans.size())
        {
            ans = path;
            return;
        }
    }
    dfs(sr, sc - 1, destr, destc, n, m, v, vis, path, 'L');
    dfs(sr, sc + 1, destr, destc, n, m, v, vis, path, 'R');
    dfs(sr + 1, sc, destr, destc, n, m, v, vis, path, 'D');
    dfs(sr - 1, sc, destr, destc, n, m, v, vis, path, 'U');
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
    int dr = -1, dc = -1;
    int sr = -1, sc = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
            {
                sr = i, sc = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'B')
            {
                dr = i, dc = j;
                break;
            }
        }
    }
    vector<vector<bool>> vis(n);
    for (auto &val : v)
    {
        for (int i = 0; i < m; i++)
        {
            val.push_back(false);
        }
    }
    vector<char> path;
    dfs(sr, sc - 1, dr, dc, n, m, v, vis, path, 'L');
    dfs(sr, sc + 1, dr, dc, n, m, v, vis, path, 'R');
    dfs(sr - 1, sc, dr, dc, n, m, v, vis, path, 'U');
    dfs(sr + 1, sc, dr, dc, n, m, v, vis, path, 'D');
    string s = "";
    for (auto &val : ans)
    {
        s += val;
    }
    cout << s << endl;
    return 0;
}