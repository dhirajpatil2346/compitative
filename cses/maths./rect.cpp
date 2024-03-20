#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
const LL mod = 1e9 + 7;

vector<LL> prefix_function(string s)
{
    LL n = (LL)s.length();
    vector<LL> pi(n);
    for (LL i = 1; i < n; i++)
    {
        LL j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

LL bin(LL a, LL p)
{
    if (p == 0)
        return 1;
    LL res = bin(a, p / 2ll);
    res = (res * res) % mod;
    if (p & 1ll)
        res = (res * a) % mod;
    return res;
}

LL mmi(LL a)
{
    return bin(a, mod - 2);
}

const LL sz = 1e7 + 5;
vector<LL> primes;
void sieve()
{
    vector<bool> isp(sz, true);
    isp[0] = false, isp[1] = false;
    for (LL i = 2; i * i <= sz; i++)
        if (isp[i])
            for (LL j = i * i; j < sz; j += i)
                isp[j] = false;
    for (int i = 2; i < sz; i++)
        if (isp[i])
            primes.push_back(i);
}
vector<vector<int>> dp(505, vector<int>(505, 1e9));
int f(int a, int b)
{
    if (a == 0 || b == 0)
        return 1e9;
    if (dp[a][b] != -1)
        return dp[a][b];
    if (a == b)
        return 0;
    int ret = 1e9;
    for (int i = 1; i < a; i++)
        ret = min(ret, 1 + f(a - i, b) + f(i, b));
    for (int i = 1; i < b; i++)
        ret = min(ret, 1 + f(a, b - i) + f(a, i));
    return dp[a][b] = ret;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < 505; i++)
        // for (int j = 0; j < 505; j++)
            dp[i][i] = 0;
    for (int i = 1; i < a + 1; i++)
    {
        for (int j = 1; j < b + 1; j++)
        {
            // cout << i << " " << j << " " << dp[i][j] << endl;
            for (int k = 1; k < i; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
            for (int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[a][b] << endl;
}
signed main()
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