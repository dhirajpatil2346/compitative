#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
LL f(int ind, int last, int n, vector<vector<LL>> &dp)
{
    // cout << ind << " " << last << endl;
    if (ind == n)
        return (last == 4);
    if (dp[ind][last] != -1)
        return dp[ind][last];
    LL r = 0;
    for (int i = 1; i <= 4; i++)
        if (i != last)
            r = (r + f(ind + 1, i, n, dp)) % mod;
    return dp[ind][last] = r;
}
LL solve()
{
    int n;
    cin >> n;
    vector<LL> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        if (i & 1)
            dp[i] = (((dp[i - 1] - 1 + mod) % mod) * 3) % mod;
        else
            dp[i] = (((dp[i - 1] + 1) % mod) * 3) % mod;
    return dp.back();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << solve() << endl;
    }
    return 0;
}
/*
1 = (prev -1) * 3 = (b-1) * 3 => 3b - 3
2 = (prev + 1) * 3 => ((b-1)*3 + 1) * 3 =( 3b - 3 + 1) * 3 => (3b - 2 ) * 3 => 9b - 6
3 = (prev - 1 ) * 3 (9b-7) * 3 => 27b - 21
4 = (prev + 1) * 3 => (27b + 20) * 3 => 81b + 60
*/