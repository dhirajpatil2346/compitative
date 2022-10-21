#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c && a == 0)
        {
            cout << 0 << endl;
        }
        else if (a == 0 || c == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            ll m = a * d, n = b * c;
            ll maxi = max(n, m);
            ll mini = min(n, m);

            long double mx = double(maxi);
            long double mn = double(mini);
            long double j = mx / mn;
            // cout << " -> " << j << endl;
            if (maxi == mini)
            {
                cout << 0 << endl;
            }
            else
            {
                if (j == j * 1ll)
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << 2 << endl;
                }
            }
        }
    }
    return 0;
}