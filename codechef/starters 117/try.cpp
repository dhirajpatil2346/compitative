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

const LL sz = sqrt(1e9) + 5;
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
    LL x, z;
    cin >> x >> z;
    while (z--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            cout << 0 << endl;
        }
        else if (q == 2)
        {
            cout << 1 << endl;
        }
        else
        {
            LL i = 0;
            LL ans = 1;
            while (i < primes.size() && (primes[i] * primes[i] <= x))
            {
                LL c = 0;
                if (x % primes[i])
                {
                }
                else
                {
                    while ((x % primes[i]) == 0)
                    {
                        c++;
                        x /= primes[i];
                    }
                    ans = (ans * c) % mod;
                }
                i++;
            }
            cout << ans << endl;
        }
    }
}
LL lcm(LL a, LL b)
{
    return (a * b) / (__gcd(a, b));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}