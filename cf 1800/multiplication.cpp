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

LL equal(LL &n, LL &m, LL &ele)
{
    LL c = 0;
    for (LL i = 1; i <= n; i++)
    {
        if ((ele % i) || (ele / i) > m)
            continue;
        c++;
    }
    return c;
}

LL Less(LL &n, LL &m, LL &ele)
{
    LL c = 0, z = ele - 1ll;
    for (LL i = 1; i <= n; i++)
    {
        c += min(m, z / i);
    }
    return c;
}

LL solve()
{
    LL n, m, k;
    cin >> n >> m >> k;
    // if (n > m)
    //     swap(n, m);
    LL L = 1, R = n * m;
    LL e = -1;
    while (L <= R)
    {
        LL ele = (L + R) / 2ll;
        if (equal(n, m, ele) + Less(n, m, ele) >= k)
        {
            e = ele;
            R = ele - 1ll;
        }
        else
            L = ele + 1ll;
    }
    return e;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << endl;
    return 0;
}