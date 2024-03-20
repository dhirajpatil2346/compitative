#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
const LL sz = 1e5 + 5;
vector<vector<vector<LL>>> dp(sz, vector<vector<LL>>(2, vector<LL>(5, -1)));
LL f(int curr, int pos, int last)
{
    // cout << curr << " " << pos << " " << last << endl;
    if (curr <= 0)
        return (pos == 0 && last == 4);
    if (dp[curr][pos][last] != -1)
        return dp[curr][pos][last];
    LL ret = f(curr - 1, abs(pos - 1), 1);
    for (int i = 2; i <= 4; i++)
    {
        ret = (ret + f(curr - i, pos, i)) % mod;
    }
    return dp[curr][pos][last] = ret;
}
void solve()
{
    LL i, ans = 0;
    cin >> i;
    f(i, 0, 0);
    cout << dp[i][0][0] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f(sz - 2, 0, 0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}