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
    double d = 1e18;
    LL sq = sqrt(d);
    if (n % 2ll == 0)
    {
        // even so even size will come
        LL l = 1, r = sq, ans = 0;
        while (l <= r)
        {
            // cout << l << " " << r << endl;
            LL sz = (l + r) / 2ll;
            LL m = sz;
            sz *= 2ll;
            LL a = 1, d = 2, N = sz;
            LL sum = (N * (2ll * a + (N - 1ll) * d)) / 2ll;
            if (sum <= n)
            {
                ans = sz;
                l = m + 1ll;
            }
            else
                r = m - 1ll;
        }
        cout << ans / 2ll << endl;
    }
    else
    {
        LL l = 1, r = n, ans = 0;
        while (l <= r)
        {
            LL sz = (l + r) / 2ll;
            LL m = sz;
            sz = sz * 2ll - 1ll;
            LL a = 1, d = 2, N = sz;
            LL sum = (N * (2ll * a + (N - 1ll) * d)) / 2ll;
            // cout << sz << " " << sum << endl;
            if (sum <= n)
            {
                ans = sz;
                l = m + 1ll;
            }
            else
                r = m - 1ll;
        }
        // cout << ans << endl;
        cout << ans / 2ll + 1ll << endl;
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
/*
8 = 1 7
16 = 1 3 5 7
16 = 1 15
*/