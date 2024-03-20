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

int f(int l, int r, int turn, vector<int> &v, vector<vector<vector<int>>> &dp)
{
    if (l > r || r < l)
        return 0;
    if (l == r)
        if (turn == 0)
            return v[l];
        else
            return 0;
    if (dp[l][r][turn] != -1)
        return dp[l][r][turn];
    if (turn == 0)
        return dp[l][r][turn] = max(v[l] + f(l + 1, r, abs(turn - 1), v, dp), v[r] + f(l, r - 1, abs(turn - 1), v, dp));
    return dp[l][r][turn] = min(f(l + 1, r, abs(turn - 1), v, dp), f(l, r - 1, abs(turn - 1), v, dp));
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    cout << f(0, n - 1, 0, v, dp) << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         for (int k = 0; k < 2; k++)
    //         {
    //             cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
    //         }
    //     }
    // }
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