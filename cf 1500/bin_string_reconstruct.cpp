#include <bits/stdc++.h>
using namespace std;
#define LL long long
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

int dp[102][102][102][2];

int f(int a, int b, int c, int last)
{
    // cout << a << " " << b << " " << c << " " << last << endl;
    if (a == 0 && b == 0 && c == 0)
        return dp[a][b][c][last] = true;
    if (a < 0 || b < 0 || c < 0)
        return false;
    if (dp[a][b][c][last] != -1)
        return dp[a][b][c][last];
    int ret = 0;
    if (last == 0)
    {
        if (a > 0)
            ret = f(a - 1, b, c, 0);
        if (b > 0)
            ret |= f(a, b - 1, c, 1);
    }
    if (last == 1)
    {
        if (c > 0)
            ret = f(a, b, c - 1, 1);
        if (b > 0)
            ret |= f(a, b - 1, c, 0);
    }
    return dp[a][b][c][last] = ret;
}

string build(int a, int b, int c, int last, string &s)
{
    // cout << a << " " << b << " " << c << " " << last << " " << s << " " << dp[a][b][c - 1][1] << endl;
    if (a == 0 && b == 0 && c == 0)
        return s;
    if (last == 0)
    {
        if (a > 0)
            if (dp[a - 1][b][c][0])
            {
                s.push_back('0');
                return build(a - 1, b, c, 0, s);
            }
        if (b > 0)
            if (dp[a][b - 1][c][1])
            {
                s.push_back('1');
                return build(a, b - 1, c, 1, s);
            }
    }
    if (last == 1)
    {
        if (c > 0 && dp[a][b][c - 1][1])
        {
            s.push_back('1');
            return build(a, b, c - 1, 1, s);
        }
        if (b > 0)
            if (dp[a][b - 1][c][0])
            {
                s.push_back('0');
                return build(a, b - 1, c, 0, s);
            }
    }
    return "";
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    f(a, b, c, 0);
    f(a, b, c, 1);
    // cout << dp[a][b][c][0] << endl;
    // cout << dp[a][b][c][1] << endl;
    if (dp[a][b][c][0])
    {
        string s = "0";
        cout << build(a, b, c, 0, s) << endl;
    }
    else
    {
        string s = "1";
        // cout << dp[a][b][c][1] << endl;
        cout << build(a, b, c, 1, s) << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 102; i++)
        for (int j = 0; j < 102; j++)
            for (int k = 0; k < 102; k++)
                for (int l = 0; l < 2; l++)
                    dp[i][j][k][l] = -1;
    for (int i = 0; i < 102; i++)
        for (int j = 0; j < 102; j++)
            for (int k = 0; k < 102; k++)
                for (int l = 0; l < 2; l++)
                    f(i, j, k, l);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}