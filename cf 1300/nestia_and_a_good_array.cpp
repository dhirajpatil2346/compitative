#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

bool isprime(ll n)
{
    ll sq = sqrt(n);
    for (ll i = 2; i <= sq; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
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
        vector<vector<ll>> ans;
        unordered_map<ll, bool> vis;
        for (ll i = 0; i < n - 1; i++)
        {
            ll mini = min(v[i], v[i + 1]);
            ll maxi = max(v[i], v[i + 1]);
            ll j = mini + 1;
            vis[v[i]] = true, vis[v[i + 1]] = true;
            while (!isprime(j))
            {
                j++;
            }
            vis[j] = true;
            v[i] = mini, v[i + 1] = j;
            vector<ll> to_push = {i + 1, i + 2, v[i], v[i + 1]};
            vis[v[i]] = true, vis[v[i + 1]] = true;
            ans.push_back(to_push);
        }
        cout << ans.size() << endl;
        for (auto &val : ans)
        {
            for (auto &valu : val)
            {
                cout << valu << " ";
            }
            cout << endl;
        }
        
                for (auto &val : v)
                {
                    cout << val << " ";
                }
                cout << endl;
                
    }

    return 0;
}