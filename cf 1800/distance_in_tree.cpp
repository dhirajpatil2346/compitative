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

void combine(vector<int> &parent, vector<int> &son)
{
    for (int i = 1; i < parent.size(); i++)
        parent[i] += son[i - 1];
}
int ans = 0;
void dfs(int sc, int par, vector<int> v[], vector<vector<int>> &dp)
{
    dp[sc][0]++;
    for (auto &child : v[sc])
    {
        if (child != par)
        {
            dfs(child, sc, v, dp);
            combine(dp[sc], dp[child]);
        }
    }
}

void f(int sc, int par, vector<int> v[], vector<vector<int>> &dp, int &k)
{
    // collect from down
    ans += dp[sc][k];
    if (par != 0)
    {
        ans += dp[par][k - 1];
        ans -= dp[sc][k - 2];
    }
    for (auto &child : v[sc])
        if (child != par)
            f(child, sc, v, dp, k);
}

void collect(int sc, int par, vector<int> v[], vector<vector<int>> &dp, vector<vector<int>> &up)
{

    if (sc == 1)
    {
        // no up is there
    }
    else
    {
        // check up of your par
        combine(up[sc], up[par]);

        // check your brothers now
        // from parent check with his dfs
        combine(up[sc], dp[par]);

        // eleminate your own dfs
        // my dp is two times upper than parent's dfs
        for (int i = 2; i < dp[sc].size(); i++)
            up[sc][i] -= dp[sc][i - 2];
    }
    for (auto &val : v[sc])
        if (val != par)
            collect(val, sc, v, dp, up);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v[n + 1], par(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(k + 2));
    vector<vector<int>> up(n + 1, vector<int>(k + 2));
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0, v, dp);
    collect(1, 0, v, dp, up);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[i][k];
        ans += up[i][k];
    }
    cout << ans / 2ll << endl;
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
/*
        1
      2
    3   5
  4
*/