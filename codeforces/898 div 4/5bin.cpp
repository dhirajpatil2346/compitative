#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, x;
    cin >> n >> x;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    LL l = 1, r = INT_MAX;
    LL ans = 0;
    while (l <= r)
    {
        LL m = (l + r) / 2ll;
        LL c = 0;
        for (auto &val : v)
        {
            if (val >= m)
                continue;
            else
                c += (m - val);
        }
        if (c <= x)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << ans << endl;
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