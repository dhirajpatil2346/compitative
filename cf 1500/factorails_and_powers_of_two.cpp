#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
#define Endl "\n"
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
vector<int> fact;
int ans = 1e12;
int bits(int n)
{
    int z = 0;
    while (n)
    {
        if (n & 1ll)
            z++;
        n /= 2ll;
    }
    return z;
}
void f(int curr, int ind, int n, int p)
{
    if (curr > n)
        return;
    if (ind == fact.size())
    {
        ans = min(ans, p + bits(n - curr));
        return;
    }
    f(curr, ind + 1, n, p);
    f(curr + fact[ind], ind + 1, n, p+1);
}

void solve()
{
    ans = 1e12;
    int n;
    cin >> n;
    f(0, 0, n, 0);
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact.push_back(1);
    for (int i = 2; fact.back() <= 1e12; i++)
        fact.push_back(i * fact.back());
    fact.pop_back();
    vector<int> nf;
    for (auto &val : fact)
        if (bits(val) != 1)
            nf.push_back(val);
    fact = nf;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}