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

int dfs(int sc, int par, vector<vector<int>> &v, vector<vector<int>> &dp, bool free)
{
    if (dp[sc][free] != -1)
        return dp[sc][free];
    int ans = 0;
    vector<int> not_take;
    for (auto &child : v[sc])
        if (par == child)
            not_take.push_back(0);
        else
            not_take.push_back(dfs(child, sc, v, dp, true));
    int acc = accumulate(not_take.begin(), not_take.end(), 0);
    if (free)
    {
        // take maximum with edge and answer
        for (int i = 0; i < not_take.size(); i++)
            if (v[sc][i] == par)
                continue;
            else
                ans = max(ans, acc - not_take[i] + 1 + dfs(v[sc][i], sc, v, dp, false));
    }
    // cout << sc << " " << par << " " << acc << " " << ans << endl;
    return dp[sc][free] = max(acc, ans);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1), dp(n + 1, vector<int>(2, -1));
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << dfs(1, 0, v, dp, true) << endl;
}
int main()
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