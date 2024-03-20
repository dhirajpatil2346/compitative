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
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    set<int> s;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            s.insert(n / i), s.insert(i);
    set<int> f;
    for (auto &val : s)
    {
        vector<vector<int>> a(val);
        for (int i = 0; i < n; i++)
            a[i % val].push_back(v[i]);
        set<int> g;
        for (auto &arr : a)
        {
            if (*max_element(arr.begin(), arr.end()) == 1 && *min_element(arr.begin(), arr.end()) == 1)
                continue;
            int gd = 0;
            for (auto &ele : arr)
                gd = __gcd(gd, ele);
            g.insert(gd);
        }
        int overall = 0;
        for (auto &valu : g)
            overall = __gcd(overall, valu);
        if (overall != 1)
            f.insert(val);
        overall = 0;
    }
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