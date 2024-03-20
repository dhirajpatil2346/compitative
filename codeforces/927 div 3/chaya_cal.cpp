#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
LL mod = 1e9 + 7;

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

LL mmi(LL a, LL tot)
{
    return bin(a, tot - 1);
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

vector<int> lg((int)3e5);
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<vector<int>> dp(n, vector<int>(31));
    for (int i = 0; i < n; i++)
        dp[i][0] = (v[i] % m);
    for (int i = 1; (i < n) && (1 << i) <= n; i++)
    {
        for (int j = 0; (j + (1 << i)) <= n; j++)
        {
            dp[j][i] = (dp[j][i - 1] * dp[j + (1 << (i - 1))][i - 1]) % m;
        }
    }
    int l = 0, r = n - 1;
    for (int p = 0; p < n; p++)
    {
        int ans = 1;
        int L = l, R = r;
        while (L <= R)
        {
            int total = R - L + 1;
            int lk = lg[total];
            ans = (ans * dp[L][lk]) % m;
            L += (1 << lk);
        }
        cout<<ans<<" ";
        char ch;
        cin >> ch;
        if (ch == 'L')
            l++;
        else
            r--;
    }
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; i < 3e5; i++)
        lg[i] = 1 + lg[i / 2];
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}