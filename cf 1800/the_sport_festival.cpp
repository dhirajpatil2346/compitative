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

LL f(LL l, LL r, vector<LL> &v, vector<vector<LL>> &dp)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    LL ret = 1e13;
    if (l > 0)
        ret = min(ret, v[r] - v[l - 1] + f(l - 1, r, v, dp));
    if (r < (v.size() - 1))
        ret = min(ret, v[r + 1] - v[l] + f(l, r + 1, v, dp));
    return dp[l][r] = ret;
}

LL solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    vector<vector<LL>> dp(n, vector<LL>(n, -1));
    dp[0][n - 1] = 0;
    LL ans = LLONG_MAX;
    for (LL i = 0; i < n; i++)
        ans = min(ans, f(i, i, v, dp));
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << endl;
    return 0;
}