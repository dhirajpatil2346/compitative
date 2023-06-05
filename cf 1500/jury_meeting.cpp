#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 998244353;
vector<LL> fact(2e5 + 1, 1);
LL bin(LL a, LL p)
{
    if (p == 0)
        return 1;
    LL res = bin(a, p / 2);
    res = (res * res) % mod;
    if (p & 1)
        res = (res * a) % mod;
    return res;
}
LL mmi(LL r) { return bin(r, mod - 2); }
LL cal(LL n, LL r)
{
    if (n == r)
        return fact[n];
    return (fact[n] * mmi(fact[n - r])) % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    // cout << fact[n] << endl;
    if ((v.back() - v[n - 2]) >= 2)
    {
        cout << 0 << endl;
        return;
    }
    if (v.back() == v[n - 2])
    {
        cout << fact[n] << endl;
        return;
    }
    LL cnt = lower_bound(v.begin(), v.end(), v.back() - 1) - v.begin();
    LL enc = n - 1;
    // cout << cnt << " " << enc << endl;
    LL tot = fact[n];
    for (int i = 0; i <= cnt; i++)
    {
        LL x = (cal(cnt, i) * fact[enc - i]) % mod;
        tot = (tot + mod - x) % mod;
    }
    cout << tot << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; i < fact.size(); i++)
        fact[i] = (fact[i - 1] * i) % mod;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}