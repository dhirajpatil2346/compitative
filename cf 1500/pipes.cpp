#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool f(int sr, int sc, int &n, vector<vector<int>> v, int last, vector<vector<vector<int>>> &dp)
{
    if (sr < 0 || sr >= 2 || sc < 0)
        return false;
    if (sc >= n)
    {
        return sr == 1;
    }
    if (dp[sr][sc][last] != -1)
        return dp[sr][sc][last];
    // int u;
    // cin >> u;
    // cout << sr << " " << sc << " " << last << endl;
    bool ret = false;
    if (last == 0)
    {
        // clear
        if (v[sr][sc] <= 2)
            ret |= f(sr, sc + 1, n, v, 2, dp);
        else
            ret |= f(sr + 1, sc, n, v, 4, dp);
    }
    if (last == 1)
    {
        // clear
        if (v[sr][sc] <= 2)
        {
            ret |= f(sr + 1, sc, n, v, 1, dp);
        }
        else
        {
            ret |= f(sr, sc + 1, n, v, 6, dp);
        }
    }
    if (last == 2)
    {

        // clear
        if (v[sr][sc] <= 2)
        {
            ret |= f(sr, sc + 1, n, v, 2, dp);
        }
        else
        {
            ret |= f(sr + 1, sc, n, v, 4, dp);
            ret |= f(sr - 1, sc, n, v, 5, dp);
        }
    }
    if (last == 3)
    {

        if (v[sr][sc] <= 2)
        {
            ret |= f(sr, sc + 1, n, v, 2, dp);
        }
        else
        {
            ret |= f(sr + 1, sc, n, v, 4, dp);
            ret |= f(sr - 1, sc, n, v, 5, dp);
        }
    }
    if (last == 4)
    {
        if (v[sr][sc] <= 2)
        {
            ret |= f(sr + 1, sc, n, v, 1, dp);
        }
        else
        {
            ret |= f(sr, sc + 1, n, v, 6, dp);
        }
    }
    else if (last == 5)
    {
        if (v[sr][sc] > 2)
        {
            ret |= f(sr, sc + 1, n, v, 3, dp);
        }
    }
    if (last == 6)
    {
        if (v[sr][sc] <= 2)
        {
            ret |= f(sr, sc + 1, n, v, 2, dp);
        }
        else
        {
            ret |= f(sr + 1, sc, n, v, 4, dp);
            ret |= f(sr - 1, sc, n, v, 5, dp);
        }
    }

    return dp[sr][sc][last] = ret;
}
void solve(vector<vector<vector<int>>> &dp)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        v[0][i] = c - '0';
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        v[1][i] = c - '0';
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n + 3; j++)
            for (int k = 0; k < 7; k++)
                dp[i][j][k] = -1;
    if (f(0, 0, n, v, 0, dp))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(200005 + 2, vector<int>(7)));
    int t;
    cin >> t;
    while (t--)
    {
        solve(dp);
    }
    return 0;
}
/*
1 ->1 6
2 ->2 4 5
3 -> 2 4 5
4 -> 1 6
5 -> 3
6 -> 2 4 5


*/