#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct st
{
    ll a, b, c;
};

st gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        st st1;
        x = 1;
        y = 0;
        st1.a = x, st1.b = 0, st1.c = a;
        return st1;
    }
    ll x1, y1;
    st ans;
    st d = gcd(b, a % b, x1, y1);
    ans.a = d.b;
    ans.b = d.a - d.b * (a / b);
    ans.c = d.c;
    return ans;
}

int main()
{
    //     ll t;
    //     cin >> t;
    //     while (t--)
    //     {
    ll n, k;
    while (scanf("%lld%lld", &n, &k) != EOF)
    {
        ll x1, y1;
        st st1 = gcd(n, k, x1, y1);
        cout << st1.a << " " << st1.b << " " << st1.c << endl;
    }
    // }
    return 0;
}