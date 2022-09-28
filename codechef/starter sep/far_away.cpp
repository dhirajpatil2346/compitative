#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        ll dist = 0;
        for (ll i = 0; i < n; i++)
        {
            dist += (max(abs(m - v[i]), abs(v[i] - 1)));
        }
        cout << dist << endl;
    }
    return 0;
}