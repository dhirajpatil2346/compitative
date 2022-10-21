#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll stringtoint(string s)
{
    ll num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ll n = s[i] - '0';
        num = num * 10 + n;
    }
    return num;
}

ll bin(ll n, ll k, ll z)
{
    if (k == 0)
    {
        return 1 % z;
    }
    if (k == 1)
    {
        return n % z;
    }
    ll res = bin(n, k / 2, z);
    if (k % 2)
    {
        return ((res % z) * (res % z) * (n % z)) % z;
    }
    else
    {
        return ((res % z) * (res % z)) % z;
    }
}

int main()
{
    ll a, b, c;
    while (scanf("%lld%lld%lld", &a, &b, &c) != EOF)
    {
        cout << bin(a, b, c) << endl;
    }
    return 0;
}