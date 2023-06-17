#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    LL k;
    cin >> n >> k;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    LL l = INT_MIN, r = INT_MAX;
    LL ans1 = accumulate(v.begin(), v.end(), 0ll) - k, ans = 1e18;
    // cout << l << " " << r << endl
    //      << endl;
    while (l <= r)
    {
        cout << l << " " << r << endl;
        LL mid = (l + r) / 2;
        if ((mid * n) > k)
        {
            r = mid - 1;
        }
        else
        {
            vector<LL> v1 = v;
            int pos = lower_bound(v.begin(), v.end(), mid) - v.begin();
            if (pos == n)
                pos--;
            LL moves = abs(mid - v1[pos]);
            v1[pos] = mid;
            LL acc = accumulate(v1.begin(), v1.end(), 0ll);
            for (int i = n - 1; i >= 0 && acc > k; i--)
            {
                if (i == pos)
                    continue;
                LL can = v1[i] - mid;
                acc -= can;
                moves++;
            }
            if (moves < ans)
            {
                ans = moves;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            // cout << mid << " " << moves << endl;
            // cout << l << " " << r << endl;
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