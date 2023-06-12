#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int f(int ind, vector<pair<int, int>> &v, int last, vector<vector<int>> &dp)
{
    if (ind == v.size() - 1)
        return 1;
    if (dp[ind][last] != -1)
        return dp[ind][last];
    int ret = f(ind + 1, v, 0, dp);
    if (last == 0)
    {
        // last was neutral or left
        int lp = v[ind - 1].first;
        // make it left
        if (lp < (v[ind].first - v[ind].second))
            ret = max(ret, 1 + f(ind + 1, v, 0, dp));
        // make it right
        int rp = v[ind + 1].first;
        if (rp > (v[ind].first + v[ind].second))
            ret = max(ret, 1 + f(ind + 1, v, 1, dp));
    }
    if (last == 1)
    {
        // last was right
        int lp = v[ind - 1].first + v[ind - 1].second;
        // make it left
        if (lp < (v[ind].first - v[ind].second))
            ret = max(ret, 1 + f(ind + 1, v, 0, dp));
        // make it right
        int rp = v[ind + 1].first;
        if (rp > (v[ind].first + v[ind].second))
            ret = max(ret, 1 + f(ind + 1, v, 1, dp));
    }
    return dp[ind][last] = ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &val : v)
        cin >> val.first >> val.second;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    vector<vector<int>> dp(n, vector<int>(2, -1));
    int ans = 1 + f(1, v, 0, dp);
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}