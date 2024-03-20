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

LL f(LL a, LL b, LL c, vector<vector<LL>> &v, vector<vector<vector<LL>>> &dp)
{
    int num = 0;
    if (dp[a][b][c] != -1)
        return dp[a][b][c];
    LL ret = 0;
    if (a > 0 && b > 0)
        ret = max(ret, v[0][a - 1] * v[1][b - 1] + f(a - 1, b - 1, c, v, dp));
    if (a > 0 && c > 0)
        ret = max(ret, v[0][a - 1] * v[2][c - 1] + f(a - 1, b, c - 1, v, dp));
    if (b > 0 && c > 0)
        ret = max(ret, v[1][b - 1] * v[2][c - 1] + f(a, b - 1, c - 1, v, dp));
    return dp[a][b][c] = ret;
}

LL solve()
{
    vector<LL> d(3);
    for (auto &val : d)
        cin >> val;
    vector<vector<LL>> v(3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < d[i]; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    for (auto &val : v)
        sort(val.begin(), val.end());
    vector<vector<vector<LL>>> dp(d[0] + 1, vector<vector<LL>>(d[1] + 1, vector<LL>(d[2] + 1, -1)));
    return f(d[0], d[1], d[2], v, dp);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << endl;
    return 0;
}