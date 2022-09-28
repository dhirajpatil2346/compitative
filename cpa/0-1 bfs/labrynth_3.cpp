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
    // cout << sr << "     " << sc << "    " << left << "  " << right << endl;
    if (sr <= 0 || sr > row || sc <= 0 || sc > col || arr[sr][sc] == '*')
    {
        return;
    }
    cout << sr << "   " << sc << " " << left << "   " << right << endl;
    vis[sr][sc] = true;
    int up = sr, down = sr;
    while (up > 0 && up <= col && arr[up][sc] != '*')
    {
        cout << sr << "   " << sc << " " << left << "   " << right << endl;
        if (vis[up][sc])
        {
            up++;
            continue;
        }
        if (left == 0 && right == 0)
        {
            vis[up][sc] = true;
            up++;
            continue;
        }
        if (left > 0)
        {
            bfs(up, sc - 1, left - 1, right);
        }
        if (right > 0)
        {
            bfs(up, sc + 1, left, right - 1);
        }
        up++;
    }
    while (down > 0 && down <= col && arr[down][sc] != '*')
    {

        cout << sr << "   " << sc << " " << left << "   " << right << endl;
        if (vis[down][sc])
        {
            down--;
            continue;
        }
        if (left == 0 && right == 0)
        {
            vis[down][sc] = true;
            down--;
            continue;
        }
        if (left > 0)
        {
            bfs(up, sc - 1, left - 1, right);
        }
        if (right > 0)
        {
            bfs(up, sc + 1, left, right - 1);
        }
        down--;
    }
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
    for (int i = 0; i < row; i++)
    {
        cin >> v[i];
    }

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

    bfs(source_row, source_column, left_c, right_c);
    cout << count();
    return 0;
}