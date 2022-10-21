#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << bin(a, b, 10) << endl;
    }
    return 0;
}