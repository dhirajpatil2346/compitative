#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int f(int sc, vector<bool> &vis, int par, vector<vector<int>> &v, int k, vector<int> &coins, vector<vector<int>> &dp, int last)
{
    vis[sc] = true;
    if (dp[sc][last] != -1)
        return dp[sc][last];
    int y = 0;
    int z = (coins[sc] >> last);
    z = max(0, z);
    int o = z - k;
    z /= 2;
    int l = last + 1;
    l = min(l, 29);
    int q = max(o, z);
    int bot = 0, div = z, mod = o;
    // div
    for (auto &child : v[sc])
    {
        if (child == par)
            continue;
        div += f(child, vis, sc, v, k, coins, dp, l);
    }
    // mod
    for (auto &child : v[sc])
    {
        if (child == par)
            continue;
        mod += f(child, vis, sc, v, k, coins, dp, last);
    }
    y += max({q, div, mod});
    // cout << sc << " " << last << " " << y << endl;
    return dp[sc][last] = y;
}

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
    {
        int n = edges.size() + 1;
        vector<vector<int>> v(n + 1);
        for (auto &val : edges)
            v[val[0]].push_back(val[1]), v[val[1]].push_back(val[0]);
        vector<vector<int>> dp(n + 1, vector<int>(30, -1));
        vector<bool> vis(n + 1, false);
        return f(0, vis, -1, v, k, coins, dp, 0);
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(2));
    for (auto &val : v)
        for (auto &valu : val)
            cin >> valu;
    vector<int> c(n + 1);
    for (auto &val : c)
        cin >> val;
    Solution sc;
    cout << sc.maximumPoints(v, c, k) << endl;
    return 0;
}