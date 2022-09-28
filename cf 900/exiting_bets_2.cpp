#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        long long gcd = abs(x - y);
        if (x == 0 || y == 0)
        {
            cout << max(x, y) << " " << 0 << endl;
        }
        else if (gcd == 0 || gcd == 1)
        {
            cout << gcd << " " << 0 << endl;
        }
        else
        {
            ll t1 = gcd - x % gcd;
            ll t3 = x % gcd;
            cout << gcd << " " << min(t1, t3) << endl;
        }
    }
    return 0;
}