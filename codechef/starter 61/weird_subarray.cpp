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
        set<pair<ll, ll>> s;
        set<pair<ll, ll>> s1;
        for (auto &val : v)
        {
            cin >> val;
        }
        ll ans = 0;
        ll i = 0;
        while (i < n)
        {
            ll start = i;
            i++;
            while (i < n && v[i] >= v[i - 1])
            {
                i++;
            }
            ll end = i;
            // cout << start << " " << end << endl;
            if (end - start <= 1)
            {
                continue;
            }
            else
            {
                // cout << "inserted 1" << endl;
                s.insert({min(start, end), max(start, end)});
            }
            // s.insert({start, end});
            ll total = end - start;
            // // cout << total << endl;
            // ans += total * (total + 1) / 2;
        }
        for (auto &val : s)
        {
            if (val.first != 0)
            {
                ans++;
            }
        }
        // cout << endl;
        i = 0;
        while (i < n)
        {
            ll start = i;
            i++;
            while (i < n && v[i] < v[i - 1])
            {
                i++;
            }
            ll end = i;
            // cout << start << " " << end << endl;
            if (end - start <= 1)
            {
                continue;
            }
            else
            {
                // cout << "inserted 2" << endl;
                s1.insert({start, end});
            }
            ll total = end - start;
            // // cout << total << endl;
            // ans += total * (total + 1) / 2;
        }
        // cout << endl;
        for (auto &val : s1)
        {
            if (val.second != n)
            {
                // ans++;
            }
        }
        for (auto &val : s)
        {
            // cout << val.second << " " << val.first << endl;
            ll total = val.second - val.first - 1;
            ans += total * (total + 1) / 2;
        }
        for (auto &val : s1)
        {
            // cout << val.second << " " << val.first << endl;
            ll total = val.second - val.first - 1;
            ans += total * (total + 1) / 2;
        }
        // cout << endl;
        cout << ans + n << endl;
    }
    return 0;
}