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

LL f(LL a, LL b, vector<LL> &p1, vector<LL> &p2, vector<vector<LL>> &dp)
{
    if (a == p1.size())
        return 0;
    if (b == p2.size())
        return 1e11;
    if (dp[a][b] != -1)
        return dp[a][b];
    LL ret = f(a, b + 1ll, p1, p2, dp);
    ret = min(ret, abs(p1[a] - p2[b]) + f(a + 1ll, b + 1ll, p1, p2, dp));
    return dp[a][b] = ret;
}

void solve()
{
    LL n, x;
    cin >> n;
    vector<LL> p1, p2;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 1)
            p1.push_back(i);
        else
            p2.push_back(i);
    }
    vector<vector<LL>> dp(p1.size(), vector<LL>(p2.size(), -1));
    cout << f(0, 0, p1, p2, dp) << endl;
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