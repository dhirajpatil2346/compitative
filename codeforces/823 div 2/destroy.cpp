#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, cost = 0;
        cin >> n >> k;
        map<ll, ll> m;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            m[x]++;
        }
        for (auto &val : m)
        {
            ll c1 = val.second;
            ll c2 = k;
            cost += min(c1, c2);
        }
        cout << cost << endl;
    }
    return 0;
}