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

map<int, char> m;

int f(int i, string &s, vector<vector<int>> &dp, vector<int> &v, int cf)
{
    // cout << i << " " << cf << endl;
    if (cf == 4)
        return 1e15;
    if (i == s.size())
        return 0;
    if (dp[i][cf] != -1)
        return dp[i][cf];
    // don't take
    int ret = v[i] + f(i + 1, s, dp, v, cf);
    //  take
    if (s[i] == m[cf])
        ret = min(ret, f(i + 1, s, dp, v, cf + 1));
    else
        ret = min(ret, f(i + 1, s, dp, v, cf));
    return dp[i][cf] = ret;
}

void solve()
{
    m[0] = 'h';
    m[1] = 'a';
    m[2] = 'r';
    m[3] = 'd';
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << f(0, s, dp, v, 0) << endl;
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