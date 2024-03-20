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

LL f(LL ind, LL T, vector<LL> &v, vector<vector<LL>> &dp)
{
    if (ind == v.size())
        return 0;
    if (T == 401)
        return 1e9;
    if (dp[ind][T] != -1)
        return dp[ind][T];
    LL ret = f(ind, T + 1, v, dp);
    ret = min(ret, abs(T - v[ind]) + f(ind + 1, T + 1, v, dp));
    return dp[ind][T] = ret;
}

void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    vector<vector<LL>> dp(n, vector<LL>(401, -1));
    cout << f(0ll, 1ll, v, dp) << endl;
}
int main()
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