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

const LL p = 31;
vector<LL> p_pow((int)5e3 + 1);

LL f(LL ind, vector<LL> &dp, unordered_map<LL, unordered_set<LL>> &m, string &s)
{
    if (ind == dp.size())
        return 1;
    if (dp[ind] != -1)
        return dp[ind];
    LL c = 0, ans = 0;
    for (LL i = ind, l = 1; i < dp.size(); i++, l++)
    {
        c += (((LL)(s[i] - 'a' + 1) * 1ll) * p_pow[l - 1]);
        if (m.find(l) != m.end() && m[l].find(c) != m[l].end())
            ans = (ans + f(i + 1, dp, m, s)) % mod;
    }
    return dp[ind] = ans;
}

void solve()
{
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % mod;
    string s;
    cin >> s;
    unordered_map<LL, unordered_set<LL>> m;
    int n;
    cin >> n;
    vector<LL> dp(s.length(), -1);
    while (n--)
    {
        string k;
        cin >> k;
        LL c = 0;
        for (int i = 0; i < k.length(); i++)
            c += (((LL)(k[i] - 'a' + 1) * 1ll) * p_pow[i]);
        m[k.length()].insert(c);
    }
    // for (auto &val : m)
    // {
    //     cout << val.first << " -> ";
    //     for (auto &valu : val.second)
    //         cout << valu << " ";
    //     cout << endl;
    // }
    cout << f(0, dp, m, s) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}