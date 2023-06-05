#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<LL> primes;
void sieve()
{
    LL N = sqrt(1e9) + 10;
    vector<bool> prime(N, true);
    prime[0] = false, prime[1] = false;
    for (LL i = 2; i < N; i++)
    {
        if (!prime[i])
            continue;
        for (LL j = i * i; j < N; j += i)
            prime[j] = false;
    }
    for (LL i = 2; i < N; i++)
        if (prime[i])
            primes.push_back(i);
}
void solve()
{
    LL a, b;
    cin >> a >> b;
    LL g = __gcd(a, b);
    if (g != b)
    {
        cout << a << endl;
        return;
    }
    map<LL, LL> m;
    LL p = g;
    LL i = 0;
    for (i = 0; i < primes.size() && p >= primes[i]; i++)
        while (p % primes[i] == 0)
            p /= primes[i], m[primes[i]]++;
    if (p > 1)
        m[p]++;
    LL vl = 0;
    for (auto &val : m)
    {
        LL org = val.second;
        LL tot = 0;
        p = a;
        while (p % val.first == 0)
            p /= val.first, tot++;
        LL diff = tot - org;
        diff++;
        LL o = 1;
        if (diff == 0)
            continue;
        while (diff--)

        
            o *= val.first;
        vl = max(vl, a / o);
    }
    cout << vl << endl;
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
    {
        solve();
    }
    return 0;
}