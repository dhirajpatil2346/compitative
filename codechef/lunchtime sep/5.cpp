#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(k);
    for (auto &val : a)
    {
        cin >> val;
    }
    for (auto &val : b)
    {
        cin >> val;
    }
    unordered_set<ll> m;
    unordered_map<ll, bool> deleted;
    for (ll i = 0; i < n; i++)
    {
        ll x = a[i];
        m.insert(x);
    }
    for (ll i = 0; i < k; i++)
    {
        if (i % 2 == 0)
        {
            for (auto val : m)
            {
                if (deleted[val] || (val % b[i]) != 0)
                {
                    continue;
                }
                deleted[val] = true;
            }
        }
        else
        {
            for (auto val : m)
            {
                if (deleted[val] || (val % b[i]) == 0)
                {
                    continue;
                }
                deleted[val] = true;
            }
        }
    }
    ll sum = 0;
    for (auto &val : m)
    {
        if (!deleted[val])
        {
            sum += val;
        }
    }
    cout << sum << endl;
    return 0;
}