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

int f(int ind, int req, vector<vector<int>> &dp)
{
    if (ind == 0)
        return (req == 0);
    if (dp[ind][req] != -1)
        return dp[ind][req];
    int ret = f(ind - 1, req, dp);
    if (req >= ind)
        ret = (ret + f(ind - 1, req - ind, dp)) % mod;
    return dp[ind][req] = ret;
}

void solve()
{
    int n;
    cin >> n;
    int sum = (n * (n + 1ll)) / 2ll;
    if (sum & 1ll)
    {
        cout << 0 << endl;
        return;
    }
    sum /= 2ll;
    // cout << sum << endl;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    cout << (f(n, sum, dp) * mmi(2)) % mod << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}