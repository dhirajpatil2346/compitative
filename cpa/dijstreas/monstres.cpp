#include <bits/stdc++.h> // Include every standard library
using namespace std;

typedef long long LL;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    int r, c;
    cin >> r >> c;
    vector<vector<pair<int, int>>> parent(r, vector<pair<int, int>>(c));
    vector<vector<char>> graph(r, vector<char>(c, '#'));
    // vector<vector<char>> move(r, vector<char>(c, '#'));
    for (auto &val : graph)
    {
        for (auto &valu : val)
        {
            cin >> valu;
        }
    }
    vector<vector<int>> mlvl(r, vector<int>(c, INT_MAX));
    vector<vector<int>> alvl(r, vector<int>(c, INT_MAX));

    // calculate mlvl
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (graph[i][j] == 'M')
                {
                    mlvl[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            int x = f.first, y = f.second;
            vector<pair<int, int>> vp = {
                {x + 1, y},
                {x - 1, y},
                {x, y + 1},
                {x, y - 1}};
            for (auto &val : vp)
            {
                int X = val.first, Y = val.second;
                if (X < 0 || X >= r || Y < 0 || Y >= c || graph[X][Y] == '#' || mlvl[X][Y] != INT_MAX)
                    continue;
                q.push(val);
                parent[X][Y] = {x, y};
                mlvl[X][Y] = mlvl[x][y] + 1;
            }
        }
    }

    // calculate alvl
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (graph[i][j] == 'A')
                {
                    alvl[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        if (!q.empty())
        {
            parent[q.front().first][q.front().second] = {-1, -1};
        }
        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            int x = f.first, y = f.second;
            if (mlvl[x][y] <= alvl[x][y])
            {
                continue;
            }
            {
                int X = x + 1, Y = y;
                if (X < 0 || X >= r || Y < 0 || Y >= c || graph[X][Y] == '#' || alvl[X][Y] != INT_MAX)
                {
                }
                else
                {
                    alvl[X][Y] = alvl[x][y] + 1;
                    if (alvl[X][Y] >= mlvl[X][Y])
                    {
                        alvl[X][Y] = INT_MAX;
                    }
                    else
                    {
                        q.push({X, Y});
                        parent[X][Y] = {x, y};
                    }
                }
            }
            {
                int X = x - 1, Y = y;
                if (X < 0 || X >= r || Y < 0 || Y >= c || graph[X][Y] == '#' || alvl[X][Y] != INT_MAX)
                {
                }
                else
                {
                    alvl[X][Y] = alvl[x][y] + 1;
                    if (alvl[X][Y] >= mlvl[X][Y])
                    {
                    }
                    else
                    {
                        q.push({X, Y});
                        parent[X][Y] = {x, y};
                    }
                }
            }
            {
                int X = x, Y = y - 1;
                if (X < 0 || X >= r || Y < 0 || Y >= c || graph[X][Y] == '#' || alvl[X][Y] != INT_MAX)
                {
                }
                else
                {
                    alvl[X][Y] = alvl[x][y] + 1;
                    if (alvl[X][Y] >= mlvl[X][Y])
                    {
                    }
                    else
                    {
                        q.push({X, Y});
                        parent[X][Y] = {x, y};
                    }
                }
            }
            {
                int X = x, Y = y + 1;
                if (X < 0 || X >= r || Y < 0 || Y >= c || graph[X][Y] == '#' || alvl[X][Y] != INT_MAX)
                {
                }
                else
                {
                    alvl[X][Y] = alvl[x][y] + 1;
                    if (alvl[X][Y] >= mlvl[X][Y])
                    {
                    }
                    else
                    {
                        q.push({X, Y});
                        parent[X][Y] = {x, y};
                    }
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (alvl[i][j] >= mlvl[i][j])
                {
                    alvl[i][j] = INT_MAX;
                }
            }
        }
    }
    int destr = -1, destc = -1;
    bool got = false;
    for (int i = 0; i < r; i++)
    {
        if (alvl[i][0] != INT_MAX)
        {
            got = true;
            destr = i, destc = 0;
        }
        else if (alvl[i][c - 1] != INT_MAX)
        {
            got = true;
            destr = i, destc = c - 1;
        }
    }
    for (int i = 0; i < c; i++)
    {
        if (alvl[0][i] != INT_MAX)
        {
            got = true;
            destr = 0, destc = i;
        }
        else if (alvl[r - 1][i] != INT_MAX)
        {
            got = true;
            destr = r - 1, destc = i;
        }
    }
    int sr = -1, sc = -1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (graph[i][j] == 'A')
            {
                sr = i, sc = j;
            }
        }
    }
    // cout << sr << " " << sc << endl
    //      << destr << " " << destc << endl;
    if (sr == -1 || sc == -1 || destr == -1 || destc == -1)
    {
        std::cout << "NO" << endl;
    }
    else if (sr == 0 || sr == r - 1 || sc == 0 || sc == c - 1)
    {
        std::cout << "YES" << endl
                  << 0 << endl;
    }
    else
    {
        pair<int, int> curr = {destr, destc};
        string ans = "";
        while (true)
        {
            if (curr.first == sr && curr.second == sc)
                break;
            pair<int, int> prev = parent[curr.first][curr.second];
            // cout << curr.first << " " << curr.second << " " << prev.first << " " << prev.second << endl;
            // char ch;
            // cin >> ch;
            if (prev.first > curr.first)
            {
                ans += "U";
                curr = prev;
            }
            else if (prev.first < curr.first)
            {
                ans += "D";
                curr = prev;
            }
            else if (prev.second > curr.second)
            {
                ans += "L";
                curr = prev;
            }
            else
            {
                // prev.second < curr.second
                ans += "R";
                curr = prev;
            }
        }
        reverse(ans.begin(), ans.end());
        if (ans.length() == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES\n"
                 << ans.length() << endl
                 << ans << endl;
        }
        // int mini = INT_MAX;
        // for (int i = 0; i < r; i++)
        // {
        //     for (int j = 0; j < c; j++)
        //     {
        //         if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
        //         {
        //             mini = min(mini, alvl[i][j]);
        //         }
        //     }
        // }
        // for (int i = 0; i < r; i++)
        // {
        //     for (int j = 0; j < c; j++)
        //     {
        //         if (alvl[i][j] > mini)
        //         {
        //             alvl[i][j] = INT_MAX;
        //         }
        //     }
        // }
        // std::cout << mini << endl;
        // std::cout << sr << " " << sc << endl;
        // vector<vector<bool>> vis(r + 5, vector<bool>(c + 5, false));
        // string a = dfs(' ', sr, sc, r, c, alvl, vis);
        // if (a.length() <= 1)
        // {
        //     std::cout << "NO" << endl;
        //     return 0;
        // }
        // if (a.length() >= 1)
        //     a = a.substr(1, a.length());
        // std::cout << "YES" << endl;
        // std::cout << a.length() << endl;
        // std::cout << a << endl;
    }

    return 0;
}