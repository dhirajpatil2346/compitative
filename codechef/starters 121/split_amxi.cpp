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
    int n;
    cin >> n;
    vector<int> m(65);
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 61; i >= 0; i--)
            if ((1ll << i) <= x)
            {
                m[i]++;
                x -= (1ll << i);
            }
    }
    int ans = m[0] & 1ll;
    int ind = 0;
    for (int i = 61; i > 0; i--)
        if (m[i] > 1)
        {
            ind = i;
            break;
        }
    if (ind == 0)
    {
        for (int i = 61; i > 0; i--)
        {
            if (m[i] & 1ll)
                ans += (1ll << i);
        }
        cout << ans << endl;
        return;
    }
    for (int i = ind + 1; i < 61; i++)
        if (m[i] > 0)
            ans += (1ll << i);
    for (; ind > 0; ind--)
        ans += (1ll << ind);
    cout << ans << endl;
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