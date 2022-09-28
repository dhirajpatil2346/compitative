#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<bool> to_delete(n + 1, false);
        vector<bool> deleted(n + 1, false);
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                // cout << i + 1 << " ";
                to_delete[i + 1] = true;
            }
        }
        // cout << endl;
        for (auto val : to_delete)
        {
            // cout << val << " ";
        }
        // cout << endl;
        ll cost = 0;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = i; j <= n; j += i)
            {
                // cout << i << " " << j << endl;
                if (deleted[j])
                {
                    continue;
                }
                else if (!to_delete[j])
                {
                    break;
                }
                else
                {
                    // cout << j << "  " << i << endl;
                    deleted[j] = true;
                    to_delete[j] = false;
                    cost += i;
                }
            }
        }
        cout << cost << endl;
    }
    return 0;
}