#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    LL extra;
    cin >> extra;
    vector<long long> curr(n), req(n);
    for (auto &val : req)
        cin >> val;
    for (auto &val : curr)
        cin >> val;
    LL ans = 0;
    LL l = 0, r = 1e10;
    while (l <= r)
    {
        LL mid = (l + r) / 2;
        LL need = 0;
        bool g = false;
        for (int i = 0; i < n; i++)
        {
            if (req[i] == 0)
                continue;
            LL real_need = req[i] * mid - curr[i];
            if (real_need <= 0)
                continue;
            if (real_need > extra)
            {
                g = true;
                break;
            }
            need += real_need;
            if (need > extra)
            {
                g = true;
                break;
            }
        }
        // cout << mid << " " << need << endl;
        if (need <= extra && g == false)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
open pipes = op 
closed pipes = cp


*/