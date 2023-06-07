#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

const LL mod = 1e9 + 7;
vector<LL> fact(2e5 + 5, 1);
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

LL mmi(LL n)
{
    return bin(n, mod - 2);
}
void solve()
{
    LL n;
    cin >> n;
    LL even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            even++;
        else
            odd++;
    }
    LL ans = bin(2, even);
    if (n == even)
    {
        ans = (ans - 1 + mod) % mod;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; i < fact.size(); i++)
        fact[i] = (i * fact[i - 1]) % mod;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
[]
[1,2]
[2,3]
[1,3]

2
4
6
24
26
246
[]
[2]

*/
/*

*/
