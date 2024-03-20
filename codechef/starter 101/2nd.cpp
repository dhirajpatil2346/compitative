#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, h;
    cin >> n >> h;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    LL ans = 1e9;
    LL l = 0, r = v.back();
    while (l <= r)
    {
        LL mid = (l + r) / 2ll;
        LL H = h;
        int i = 0;
        while (i < n)
        {
            if (v[i] <= mid)
            {
                i++;
            }
            else if (H > v[i])
            {

                H -= v[i];
                i++;
            }
            else
                break;
        }
        // cout << mid << " " << i << endl;
        if (i == n)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
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