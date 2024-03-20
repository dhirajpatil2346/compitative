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

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<int> lg(n + 1);
    for (int i = 2; i < n; i++)
        lg[i] = 1 + lg[i / 2];
    vector<vector<int>> dp(n, vector<int>(30, 1e9 + 1));
    for (int i = 0; i < n; i++)
        dp[i][0] = v[i];
    for (int i = 1; i < 31; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
    for (int i = 0; i < n; i++)
    {
        int r = i - 1, l = 0, ans = 0;
        while (l <= r)
        {
            int L = (l + r) / 2, R = i - 1;
            // find min from L to R
            int tot = R - L + 1;
            int lk = lg[tot];
            int value = min(dp[L][lk], dp[R + 1 - (1 << lk)][lk]);
            if (value < v[i])
            {
                ans = L + 1;
                l = L + 1;
            }
            else
                r = L - 1;
        }
        cout << ans << " ";
    }
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