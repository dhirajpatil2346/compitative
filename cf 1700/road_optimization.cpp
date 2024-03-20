#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

LL f(LL ind, LL leftK, LL &n, LL &l, vector<LL> &sign, vector<LL> &speed, vector<vector<LL>> &dp)
{
    if (ind >= n)
        return 0;
    if (ind == n - 1)
    {
        LL diff = l - sign[n - 1];
        return diff * speed[n - 1];
    }
    if (dp[ind][leftK] != -1)
        return dp[ind][leftK];
    LL ret = 1e12;
    for (LL j = ind + 1, used = 0; j <= n && used <= leftK; j++, used++)
    {
        if (j == n)
        {
            LL diff = l - sign[ind];
            ret = min(ret, diff * speed[ind]);
            break;
        }
        else
        {
            LL diff = sign[j] - sign[ind];
            LL cost = diff * speed[ind];
            ret = min(ret, cost + f(j, leftK - used, n, l, sign, speed, dp));
        }
    }
    return dp[ind][leftK] = ret;
}

void solve()
{
    LL n, l, k;
    cin >> n >> l >> k;
    vector<LL> sign(n), speed(n);
    for (auto &val : sign)
        cin >> val;
    for (auto &val : speed)
        cin >> val;
    vector<vector<LL>> dp(n + 1, vector<LL>(k + 1, -1));
    cout << f(0, k, n, l, sign, speed, dp) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}