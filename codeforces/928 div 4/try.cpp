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

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    int start = 1;
    vector<int> v = {n / 2 + n % 2, 1 + (n - 2ll) / 4ll};
    vector<int> s = {1, 2};
    for (int start = 4; start <= n; start *= 2ll)
    {
        s.push_back(start);
        int newf = start * 2ll;
        v.push_back(1);
        v.back() += ((n - start) / newf);
    }
    for (int i = 1; i < v.size(); i++)
        v[i] += v[i - 1];
    int ind = lower_bound(v.begin(), v.end(), k) - v.begin();
    if (ind == 0)
    {
        cout << k * 2ll - 1ll << endl;
    }
    else
    {
        k -= v[ind - 1];
        k--;
        cout << s[ind] + k * 2ll * s[ind] << endl;
    }
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