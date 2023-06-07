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
    LL N = n;
    LL a = 0;
    while (n--)
    {
        int A;
        cin >> A;
        if (A % 2 == 0)
            a++;
    }
    LL even = bin(2, a);
    // cout << even << endl;
    LL odd = N - a;
    // sum from 0 to odd - 1 total odd
    odd = ((odd) * (odd - 1)) / 2;
    odd %= mod;
    even = (even * odd) % mod;
    cout << even << endl;
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
[13]
[15]
[17]
[35]
[37]
[57]


*/