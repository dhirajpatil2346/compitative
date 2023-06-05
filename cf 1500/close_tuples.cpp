#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

const LL mod = 1e9 + 7;

vector<long long> fact(2e5 + 10);
void sieve()
{
    for (int i = 0; i < fact.size(); i++)
    {
        fact[i] = i;
    }
    fact[0] = 1;
    for (int i = 1; i < fact.size(); i++)
    {
        fact[i] *= fact[i - 1];
        fact[i] %= mod;
    }
}
/*
1 1 2 2 3 4 5 6 8 9
6 3 3 1 1 1 0 0 0 0
*/

LL bin(LL a, LL b)
{
    if (b == 0)
        return 1;
    LL res = bin(a, b / 2);
    res = (res * res) % mod;
    res %= mod;
    if (b & 1)
    {
        res = (res * a) % mod;
        res %= mod;
    }
    return res;
}

LL mmi(LL n)
{
    return bin(n, mod - 2) % mod;
}

void solve()
{
    LL n, m, k;
    cin >> n >> m >> k;
    LL ans = 0;
    vector<long long> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    for (LL i = 0; i < n; i++)
    {
        LL pos1 = i;
        LL pos2 = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin() - 1;
        LL ele = pos2 - pos1;
        if (ele < m - 1)
            continue;
        LL curr = ((fact[ele] % mod) * (mmi(fact[m - 1]) % mod)) % mod;
        curr = (curr * mmi(fact[ele - (m - 1)])) % mod;
        curr %= mod;
        ans = (curr + ans) % mod;
        ans %= mod;
    }
    cout << ans << endl;
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