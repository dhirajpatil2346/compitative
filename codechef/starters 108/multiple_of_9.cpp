#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

LL f(LL ind, LL mod, vector<vector<LL>> &dp)
{
    if (ind == 0)
    {
        if (mod == 0)
            return 1ll;
        return 0;
    }
    if (dp[ind][mod] != -1)
        return dp[ind][mod];
    LL ret = 0;
    for (LL i = 0; i <= 9; i++)
        ret += f(ind - 1, (mod + i) % 9ll, dp);
    return dp[ind][mod] = ret;
}

void solve(vector<vector<LL>> &dp)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    LL opt = count(s.begin(), s.end(), '?');
    LL mod = 0;
    for (int i = 0; i < n; i++)
        if (s[i] != '?')
            mod = (mod + (s[i] - '0')) % 9;
    if (opt == 0)
    {
        if (mod == 0)
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
        return;
    }
    LL ans = 0;
    if (s[0] == '?')
        for (LL i = 1; i <= 9; i++)
            ans += f(opt-1, (mod + i) % 9ll, dp);
    else
        ans = f(opt, mod, dp);
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL opt = 1e5 + 5;
    vector<vector<LL>> dp(opt, vector<LL>(10, -1));
    for (LL i = 0 ; i < opt ; i++)
    {
        for (LL mod = 8; mod >= 0; mod--)
            f(i, mod, dp);
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve(dp);
    }
    return 0;
}