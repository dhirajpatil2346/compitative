#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL _, I, d, h, ans = 1e9;
    cin >> _ >> I;
    bool sat = false;
    vector<pair<LL, LL>> vp(_);
    for (auto &val : vp)
        cin >> val.first >> val.second;
    LL mx = 0;
    for (auto &val : vp)
        mx = max(mx, val.first);
    for (LL j = 0; j < _; j++)
    {
        d = vp[j].first, h = vp[j].second;
        if (mx >= I)
        {
            sat = true;
            ans = min(ans, 1ll);
            continue;
        }
        if (h >= d)
            continue;
        LL ca = 1 + (I - mx) / (d - h) + min(1ll, (I - mx) % (d - h));
        // cout << " __ " << ca << endl;
        ans = min(ans, ca);
        sat = true;
    }
    if (!sat)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
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