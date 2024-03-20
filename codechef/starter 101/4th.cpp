#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
LL sieve(LL a, LL p)
{
    if (p == 0)
        return 1;
    LL res = sieve(a, p / 2ll);
    res = (res * res) % mod;
    if (p & 1ll)
        res = (res * a) % mod;
    return res;
}

LL f(LL cl, LL cr, LL &L, LL &R, LL a, LL d, LL &mz)
{
    if (cr < L)
        return 0;
    if (cl > R)
        return 0;
    if (cl >= L && cr <= R)
    {
        LL n = cr - cl + 1ll;
        LL sum = n;
        LL block = (2 * a) % mod;
        block = (block + ((n - 1ll) * d) % mod) % mod;
        sum = (sum * block) % mod;
        sum = (sum * mz) % mod;
        return sum;
    }
    LL ele = cr - cl + 1ll;
    LL next = cl + ele / 2;
    return (f(cl, next - 1ll, L, R, a, d * 2ll, mz) + f(next, cr, L, R, a + d, 2ll * d, mz)) % mod;
}

LL solve(LL &mz)
{
    LL n, L, R;
    cin >> n >> L >> R;
    return f(1, n, L, R, 1ll, 1ll, mz);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    LL mz = sieve(2ll, mod - 2ll);
    while (t--)
    {
        cout << solve(mz) << endl;
    }
    return 0;
}