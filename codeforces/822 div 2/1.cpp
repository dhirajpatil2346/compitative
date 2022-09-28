#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
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
        sort(v.begin(), v.end());
        ll ans = INT_MAX;
        for (ll i = 0; i < n - 2; i++)
        {
            ll sum = v[i] + v[i + 1] + v[i + 2];
            ll avg = sum / 3;
            ll inc = abs(v[i] - v[i + 1]) + abs(v[i + 1] - v[i + 1]) + abs(v[i + 1] - v[i + 2]);
            ans = min(ans, inc);
        }
        cout << ans << endl;
    }
    return 0;
}

/*
1 + 1 +3+ 4

*/