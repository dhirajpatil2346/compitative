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

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 0; (i < primes.size()) && (primes[i] * primes[i]) <= n; i++)
        if ((n % primes[i]) == 0)
            return false;
    return true;
}
void solve()
{
    int n;
    cin >> n;
    if (isPrime(n))
    {
        cout << 1 << endl
             << n << endl;
        return;
    }
    if (isPrime(n - 2))
    {
        cout << 2 << endl
             << n - 2 << " " << 2 << endl;
        return;
    }
    // now process
    int even = -1;
    vector<int> v;
    for (int i = 4; i <= n; i += 2)
    {
        if (isPrime(n - i))
        {
            even = i;
            v.push_back(n - i);
            break;
        }
    }
    // cout << isPrime(23) << Endl;
    // cout << even << endl;
    // now find two for even
    for (int i = 0; i < primes.size(); i++)
    {
        if (isPrime(even - primes[i]))
        {
            v.push_back(primes[i]);
            v.push_back(even - primes[i]);
            break;
        }
    }
    cout << v.size() << endl;
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    // for (int i = 0; i < 10; i++)
    //     cout << primes[i] << " ";
    // cout << endl;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}