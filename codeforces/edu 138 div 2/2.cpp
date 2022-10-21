#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> v;
        ll sc = 0;
        vector<ll> v1(n), v2(n);
        for (auto &val : v1)
        {
            cin >> val;
        }
        for (auto &val : v2)
        {
            cin >> val;
        }
        for (ll i = 0; i < n; i++)
        {
            ll x, y;
            x = v1[i], y = v2[i];
            if (y == 0)
            {
                sc += x;
            }
            else
            {
                v.push_back({x, y});
            }
        }
        ll i = 0, j = v.size() - 1;
        while (i < j)
        {
            if (v[i].second <= v[j].second)
            {
                sc += v[i].first;
                v[i + 1].first += v[i].second;
                i++;
            }
            else
            {
                sc += v[j].first;
                v[j - 1].first += v[j].second;
                j--;
            }
        }
        if (v.size() >= 1)
        {
            sc += v[i].first;
        }
        cout << sc << endl;
    }
    return 0;
}