#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll m = 1e9 + 7;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x, y;
    cin >> x >> y;
    ll a[8];
    a[0] = x, a[1] = y, a[2] = y - x, a[3] = -x, a[4] = -y, a[5] = x - y;
    ll n;
    cin >> n;
    cout << (a[(n - 1) % 6] % m + m) % m << endl;
    return 0;
}