#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
char arr[N][N];
bool vis[N][N];
int l_left[N][N];
int r_right[N][N];
// map<pair<int, int>, pair<int, int>> um;
int row, col, source_row, source_column, left_c, right_c;
void bfs(int sr, int sc, int left, int right)
{
    // //cout << row << col << source_row << source_column << left_c << right_c << endl;
    if (sr <= 0 || sr > row || sc <= 0 || sc > col)
    {
        return;
    }
    if (arr[sr][sc] == '*')
    {
        return;
    }
    vis[sr][sc] = true;
    /*
    pair<int, int> p{left, right};
    if (um[{sr, sc}] == p)
    {
        return;
    }
    um[{sr, sc}] = p;
    */



   /*
    bfs(sr + 1, sc, left, right);
    bfs(sr - 1, sc, left, right);
    if (left > 0)
    {
        bfs(sr, sc - 1, left - 1, right);
    }
    if (right > 0)
    {
        bfs(sr, sc + 1, left, right - 1);
    }
*/
}
void setit()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = '*';
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vis[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            l_left[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            r_right[i][j] = 0;
        }
    }
}
int count()
{
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j])
            {
                c++;
            }
        }
    }
    return c;
}

int main()
{
    setit();
    cin >> row >> col >> source_row >> source_column >> left_c >> right_c;
    vector<string> v(row);
    // cout << row << col << source_row << source_column << left_c << right_c << endl;
    for (int i = 0; i < row; i++)
    {
        cin >> v[i];
    }
    // cout << row << col << source_row << source_column << left_c << right_c << endl;
    int curr = 1;
    for (auto &val : v)
    {
        int z = 1;
        for (auto &valu : val)
        {
            arr[curr][z] = valu;
            z++;
        }
        curr++;
    }
    // cout << row << "    " << col << endl;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            // cout << arr[i][j];
        }
        // cout << endl;
    }

    bfs(source_row, source_column, left_c, right_c);
    cout << count();
    return 0;
}