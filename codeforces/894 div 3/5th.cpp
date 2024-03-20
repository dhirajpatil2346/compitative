#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, m, d;
    cin >> n >> m >> d;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    LL csum = 0;
    multiset<LL> ms;
    LL cost = 0;
    for (LL i = 0; i < n; i++)
    {
        LL ccst = 0;
        ccst -= ((i + 1ll) * d);
        if (v[i] < 0)
            continue;
        else
        {
            if (ms.size() < m)
            {
                ms.insert(v[i]);
                csum += v[i];
            }
            else
            {
                if ((v[i] > *ms.begin()))
                {
                    csum -= *ms.begin();
                    ms.erase(ms.begin());
                    ms.insert(v[i]);
                    csum += v[i];
                }
                else
                    continue;
            }
        }
        ccst += csum;
        cost = max(cost, ccst);
    }
    cout << cost << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}