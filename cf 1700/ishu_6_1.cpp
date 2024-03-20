#include <bits/stdc++.h>
using namespace std;

long long f(int curr, int ind, long long n, vector<vector<long long>> &dp)
{
    long long ret = 0;
    if (curr == n)
        return 1;
    if (curr > n)
        return 0;
    if (dp[curr][ind] != -1)
        return dp[curr][ind];
    ret += f(curr + 1, ind + 1, n, dp);
    ret += f(curr + 2, ind + 1, n, dp);
    return dp[n][ind] = ret;
}
int main()
{
    long long n;
    cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[n] = 1;
    dp[n - 1] = 2;
    for (int i = n - 2; i >= 1; i--)
    {
        dp[i] = dp[i + 1] + dp[i + 2];
    }
    cout << dp[1] << endl;
    return 0;
}