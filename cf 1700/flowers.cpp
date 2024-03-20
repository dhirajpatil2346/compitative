#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<LL> red(1e5 + 1), white(1e5 + 1);
    red[0] = 1;
    for (int i = 1; i <= k; i++)
        red[i] = 1;
    white[k] = 1;
    for (int i = k + 1; i <= 1e5; i++)
    {
        red[i] = (red[i] + red[i - 1]) % mod;
        red[i] = (red[i] + white[i - 1]) % mod;
        white[i] = (white[i - k] + white[i]) % mod;
        white[i] = (red[i - k] + white[i]) % mod;
    }
    vector<LL> dp(1e5 + 1);
    for (int i = 1; i <= 1e5; i++)
        dp[i] = (red[i] + white[i]) % mod;
    for (int i = 1; i <= 1e5; i++)
        dp[i] = (dp[i] + dp[i - 1]) % mod;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        LL z = dp[b] - dp[a - 1];
        z = (z + mod) % mod;
        cout << z << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}