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

void solve()
{
    string s;
    cin >> s;
    int p = 31;
    vector<int> p_pow(s.length());
    p_pow[0] = 1;
    for (int i = 1; i < s.length(); i++)
        p_pow[i] = (p * p_pow[i - 1]) % mod;
    int ans = 0;
    for (int i = 1; i <= s.length(); i++)
    {
        int curr_h = 0;
        set<int> curr;
        for (int j = 0; j < i; j++)
            curr_h = (curr_h + ((LL)(s[j] - 'a' + 1)) * p_pow[j]) % mod;
        curr.insert(curr_h);
        for (int j = i, k = 0; j < s.length(); j++, k++)
        {
            curr_h = (curr_h - (LL)(s[k] - 'a' + 1) + mod) % mod;
            curr_h = (curr_h * mmi(p)) % mod;
            curr_h = (curr_h + ((LL)(s[j] - 'a' + 1)) * p_pow[i-1]) % mod;
            curr.insert(curr_h);
        }
        // cout << i << " --> ";
        // for (auto &val : curr)
        //     cout << val << " ";
        // cout << endl;
        ans += (LL)curr.size();
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}