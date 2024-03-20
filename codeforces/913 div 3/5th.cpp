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

const LL sz = 1e7 + 1;
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
// const int sz = 1e7 + 1;
vector<int> sum(sz, 0);
map<int, vector<int>> one;
vector<vector<vector<LL>>> dp(55, vector<vector<LL>>(sz, vector<LL>(4, -1)));

LL f(LL n, LL s, LL need)
{
    if (need == 1)
        return sum[n] == s;
    // s , n , need
    if (dp[s][n][need] != -1)
        return dp[s][n][need];
    LL ret = 0;
    for (int i = 0; i <= s; i++)
    {
        for (auto &val : one[i])
        {
            if (val > n)
                break;
            ret += (n - val, s - i, need - 1);
        }
    }
    return dp[s][n][need] = ret;
}

void sv()
{
    for (int i = 0; i < sz; i++)
    {
        int s = 0;
        int x = i;
        while (x)
        {
            s += (x % 10);
            x /= 10;
        }
        sum[i] = s;
    }

    for (int i = 0; i < sz; i++)
        one[sum[i]].push_back(i);
}
void solve()
{
    LL n;
    cin >> n;
    cout << f(n, sum[n], 3) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sv();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}