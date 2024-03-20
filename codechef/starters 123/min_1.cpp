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

vector<int> dfs(int sc, int par, vector<int> v[], vector<int> &dp, int &k)
{
    vector<int> ret;
    // base
    if (sc != 1 && v[sc].size() == 1)
    {
        dp[sc] = 1;
        ret = {k};
    }
    // dfs
    for (auto &child : v[sc])
        if (child != par)
        {
            vector<int> z = dfs(child, sc, v, dp, k);
            for (auto &val : z)
                if (val != 0)
                    ret.push_back(val - 1);
        }
    dp[sc] = ret.size();
    return ret;
}

int f(int sc, int par, vector<int> &dp, vector<int> v[], vector<int> &ans)
{
    if (sc != 1 && v[sc].size() == 0)
        return ans[sc] = 1;
    int ret = dp[sc];
    for (auto &child : v[sc])
        if (child != par)
            ret = max(ret, dp[sc] - dp[child] + f(child, sc, dp, v, ans));
    return ans[sc] = ret;
}

void g(int sc, int par, vector<int> v[], vector<int> &dp, vector<int> &fd)
{
    for (auto &child : v[sc])
        if (child != par)
            fd[sc] += dp[child], g(child, sc, v, dp, fd);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v[n + 1], dp(n + 1), ans(n + 1), fd(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0, v, dp, k);
    g(1, 0, v, dp, fd);
    // for (auto &val : fd)
    //     cout << val << " ";
    // cout << endl;
    f(1, 0, fd, v, ans);
    cout << ans[1] << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}