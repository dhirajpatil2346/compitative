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
        vector<ll> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        long long sum = accumulate(v.begin(), v.end(), 0ll);
        ll zsum = 0;
        ll ans = n;
        for (ll i = 0; i < n; i++)
        {
            zsum += v[i];
            if (sum % zsum || i == n - 1)
            {
                continue;
            }
            else
            {
                // cout << zsum << endl;
                ll maxp = 1;
                bool failed = false;
                ll j = 0;
                ll start = 0;
                ll csum = 0;
                while ((failed == false) && (j < n) && (csum < zsum))
                {
                    // cout << j << endl;
                    csum += v[j];
                    if (csum == zsum)
                    {
                        maxp = max(maxp, j - start + 1);
                        // cout << start << " " << j << endl;
                        csum = 0;
                        j++;
                        start = j;
                    }
                    else if (csum > zsum)
                    {
                        failed = true;
                    }
                    else
                    {
                        j++;
                    }
                }

                if (failed)
                {
                    continue;
                }
                else
                {
                    ans = min(ans, maxp);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}