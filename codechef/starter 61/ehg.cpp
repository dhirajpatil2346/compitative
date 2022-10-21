#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        ll i = n - 1;
        ll j = 0;
        ll c = 0;
        ll ans = 0;
        while (i >= 0)
        {
            ll key = v[i];
            while (i >= 0 && v[i] <= key)
            {
                key = v[i];
                i--;
                c++;
            }
            // cout << "  " << i << endl;
            if (i > 0)
            {
                j++;
                c++;
                i--;
                ans += (c * (c + 1)) / 2;
                c = 1;
            }
            else if (i == 0)
            {
                // j++;
                c++;
                i--;
                ans += (c * (c + 1)) / 2;
                c = 1;
            }
            else
            {
                ans += (c * (c + 1)) / 2;
                c = 1;
            }

            // cout << c << endl;
        }
        // cout << j << endl;
        cout << ans - j / 2 - j % 2 << endl;
    }
    return 0;
}