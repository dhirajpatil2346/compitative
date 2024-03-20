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

int f(int ind, vector<int> &v, vector<int> &dp, vector<int> &len)
{
    // cout << ind << endl;
    int ch;
    // cin >> ch;
    if (ind >= dp.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int ret = f(ind + 1, v, dp, len);
    if (len[ind] != 0 && v[ind] != 0)
        ret = max(ret, v[ind] + f(len[ind], v, dp, len));
    return dp[ind] = ret;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), len(n + 1), dp(n + 1, -1);
    vector<pair<int, int>> vp(m);
    for (auto &val : vp)
    {
        cin >> val.first >> val.second;
        v[val.first]++;
        if ((val.second + 1) < v.size())
            v[val.second + 1]--;
        len[val.first] = max(len[val.first], val.second + 1);
    }

    // for (int i = 1; i <= n; i++)
    //     cout << v[i] << " ";
    // cout << endl;
    for (int i = 1; i < n + 1; i++)
    {
        v[i] += v[i - 1];
        len[i] = max({i + 1, len[i], len[i - 1]});
    }
    // for (int i = 1; i <= n; i++)
    //     cout << len[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << v[i] << " ";
    // cout << endl;
    cout << f(1, v, dp, len) << endl;
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