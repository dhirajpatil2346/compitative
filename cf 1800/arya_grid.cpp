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
    int n, ans = 0;
    cin >> n;
    vector<int> v;
    while (n > 0)
    {
        if (n & 1)
            v.push_back(1);
        else
            v.push_back(0);
        n /= 2;
    }
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
    n = v.size();
    // reverse(v.begin(), v.end());
    for (int i = 0; i <= n - 3; i++)
    {
        if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 1)
        {
            ans += (1 << i);
            for (int j = i; j < n; j++)
            {
                if (v[j] == 0)
                {
                    v[j] = 1;
                    break;
                }
                else
                    v[j] = 0;
            }
        }
    }
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