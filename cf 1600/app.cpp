#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<LL> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    LL thresh = min(v[0], k / n);
    LL ans = abs(v[0] - thresh);
    LL prevsum = accumulate(v.begin(), v.end(), 0ll);
    LL sum = accumulate(v.begin(), v.end(), 0ll) + thresh;
    sum -= v[0];
    for (int i = n - 1; i > 0 && sum > k; i--)
    {
        ans++;
        sum -= v[i];
        sum += thresh;
    }
    LL l = -1e15, r = thresh - 1;
    cout << thresh << " " << ans << endl;
    while (l <= r)
    {
        LL csum = prevsum;
        LL mid = (l + r) / 2.0;
        LL cans = abs(v[0] - mid);
        csum -= v[0];
        csum += mid;
        for (int i = n - 1; i > 0 && csum > k; i--)
        {
            cans++;
            sum -= v[i];
            sum += mid;
        }
        cout << mid << " " << cans << endl;
        if (cans < ans)
        {
            thresh = mid;
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