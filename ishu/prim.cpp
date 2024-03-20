#include <bits/stdc++.h>
using namespace std;

bool isP(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; (i * i) <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int f(int n, vector<int> &v, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ret = 1e5;
    for (auto &val : v)
    {
        if (val <= n)
            ret = min(ret, 1 + f(n - val, v, dp));
    }
    return dp[n] = ret;
}

int CoinsDeterminer(int n)
{
    vector<int> v = {1, 5, 7, 9, 11};
    vector<int> dp(n + 1, -1);
    return f(n, v, dp);
}

void solve()
{
    int n;
    cin >> n;
    cout << CoinsDeterminer(n) << endl;
    // cout << PrintChecker(n) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}