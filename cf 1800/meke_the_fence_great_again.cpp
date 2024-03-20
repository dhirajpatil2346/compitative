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

LL f(LL ind, vector<LL> &height, vector<LL> &cost, vector<LL> &dp)
{
    if (ind >= height.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    LL front = 0, back = 0;
    if (ind > 0)
        back = height[ind - 1];
    if ((ind + 1) < height.size())
        front = height[ind + 1];
    LL ret = 1e18 + 1;
    if (height[ind] < front && height[ind] < back)
        ret = f(ind + 1, height, cost, dp);
    
    return 0;
}

void solve()
{
    LL n;
    cin >> n;
    vector<LL> height(n), cost(n), dp(n, -1);
    for (int i = 0; i < n; i++)
        cin >> height[i] >> cost[i];
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