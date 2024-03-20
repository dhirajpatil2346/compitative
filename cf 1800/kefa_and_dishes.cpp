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
int n, m;
map<pair<int, int>, int> mp;
int f(int c, int last, vector<int> v, vector<vector<int>> &dp)
{
    if (__builtin_popcount(c) == m)
        return 0;
    if (dp[c][last] != -1)
        return dp[c][last];
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((c & (1 << i)))
            continue;
        int u = v[i];
        if (mp.find({last, i}) != mp.end())
            u += mp[{last, i}];
        u += f(c + (1 << i), i, v, dp);
        ret = max(ret, u);
    }
    return dp[c][last] = ret;
}

void solve()
{
    int k;
    int ans = 0;
    cin >> n >> m >> k;
    vector<int> v(19);
    vector<vector<int>> dp((1 << (n + 1)), vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mp[{a, b}] = c;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[1 << i][i] = v[i];
        ans = max(ans, v[i]);
    }

    for (int i = 2; i < (1 << (n + 1)); i += 2)
    {
        vector<int> bits;
        for (int j = 1; j <= n; j++)
            if (i & (1 << j))
                bits.push_back(j);
        if (bits.size() > m)
            continue;
        for (int j = 0; j < bits.size(); j++)
            for (int k = 0; k < bits.size(); k++)
                if (j != k)
                {
                    int b1 = bits[j], b2 = bits[k];
                    // going from b1 to b2
                    int u = v[b2];
                    // cout << i << " " << b1 << " " << b2 << endl;
                    if (mp.find({b1, b2}) != mp.end())
                        u += mp[{b1, b2}];
                    dp[i][b2] = max(dp[i][b2], u + dp[i - (1 << b2)][b1]);
                    ans = max(ans, dp[i][b2]);
                }
        // cout << i << " " << dp[i] << endl;
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        // cout << (18ll * 18ll * bin(2ll, 19))/1e7 << endl;
        solve();
    }
    return 0;
}