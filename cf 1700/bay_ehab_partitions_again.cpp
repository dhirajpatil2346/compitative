#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
#define Endl "\n"
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

int f(int ind, int left, vector<int> &v, vector<vector<int>> &dp)
{
    if (left < 0)
        return 1e9;
    if (ind < 0)
        if (left == 0)
            return 0;
        else
            return 1e9;
    if (left == 0)
        return dp[ind][left] = 0;
    if (dp[ind][left] != -1)
        return dp[ind][left];
    int ret = f(ind - 1, left, v, dp);
    ret = min(ret, 1 + f(ind - 1, left - v[ind], v, dp));
    return dp[ind][left] = ret;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    int total = accumulate(v.begin(), v.end(), 0ll);
    vector<vector<int>> dp(n, vector<int>(total + 1, -1));
    for (int i = 0; i <= total; i++)
        f(n - 1, i, v, dp);
    for (auto &val : dp)
        for (auto &valu : val)
            if (valu > n)
                valu = -1;
    int ans = n, Y = -1;
    // for (auto &val : dp[0])
    //     cout << val << " ";
    // cout << endl;
    for (int y = 0; y <= total; y++)
    {
        // 2x + y = total
        int x = total - y;
        // cout << y << " " << x << endl;
        if (dp.back()[y] == -1)
            continue;
        if (x & 1)
        {
            // cout << y << endl;
            if (ans > dp.back()[y])
                Y = y;
            ans = min(ans, dp.back()[y]);
            continue;
        }
        x /= 2;
        if (dp.back()[y + x] == -1)
        {
            // cout << y  << endl;
            if (ans > dp.back()[y])
                Y = y;
            ans = min(ans, dp.back()[y]);
        }
    }
    // Y is the sum i want to get
    cout << dp.back()[Y] << endl;
    // cout << Y << endl;
    int ind = n - 1;
    while (Y && ind >= 0)
    {
        // if (ind > 0 && Y >= v[ind])
        //     cout << ind << " " << Y << " " << dp[ind][Y] << " " << dp[ind - 1][Y - v[ind]] << endl;
        if (dp[ind][Y] != -1)
        {
            if (ind == 0)
            {
                cout << ind + 1 << " ";
                Y -= v[ind];
            }
            else if (Y >= v[ind] && dp[ind][Y] != -1 && dp[ind - 1][Y - v[ind]] != -1)
            {
                cout << ind + 1 << " ";
                Y -= v[ind];
            }
        }
        ind--;
    }
    cout << endl;
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