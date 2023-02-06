#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    */
    bool vis[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
        }
    }

    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vis[i][j];
        }
        cout << endl;
    }
    */
    int sc = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == true)
            {
                continue;
            }
            if (arr[i][j] == '.')
            {
                vis[i][j] = true;
                continue;
            }
            if (arr[i][j] == 'W')
            {
                continue;
            }
            else
            {
                vector<pair<int, int>> v(4);
                v[0] = {i + 1, j};
                v[1] = {i - 1, j};
                v[2] = {i, j - 1};
                v[3] = {i, j + 1};
                for (auto &val : v)
                {
                    int x = val.first, y = val.second;
                    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || arr[x][y] != 'W')
                    {
                        continue;
                    }
                    vis[x][y] = true;
                    // cout << x << " " << y << endl;
                    sc++;
                    break;
                }
            }
        }
    }

    cout << sc << endl;
    return 0;
}