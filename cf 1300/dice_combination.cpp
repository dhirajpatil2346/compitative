#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll total = 0;
const ll m = 1e9 + 7;

ll ways(ll n, const vector<ll> &v, vector<ll> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    ll ans = 0;
    for (ll i = 0; i < 6; i++)
    {
        ll subAns = 0;
        if (n - v[i] >= 0)
        {
            if (dp[n - v[i]] != -1)
            {
                subAns = dp[n - v[i]];
            }
            else
            {
                subAns = ways(n - v[i], v, dp);
            }
            ans += subAns;
            ans = ans % m;
        }
    }
    dp[n] = ans;
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> v = {1, 2, 3, 4, 5, 6};
    vector<ll> dp(n + 1, -1);
    dp[0] = 1;
    ways(n, v, dp);
    cout << dp[n] << endl;
    return 0;
}