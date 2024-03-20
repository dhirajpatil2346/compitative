#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    if (accumulate(v.begin(), v.end(), 0ll) <= k)
    {
        cout << 0 << endl;
        return;
    }
    map<LL, LL> m;
    m[n - 1] = 0;
    LL sum = 0;
    for (LL j = n - 2, i = 1; i < n; i++, j--)
    {
        sum += v[i];
        m[j] = sum;
    }
    LL cost = 1e18;
    {
        LL ccst = 0;
        LL thresh = k / n;
        thresh = min(thresh, v[0]);
        LL csum = accumulate(v.begin(), v.end(), 0ll);
        csum -= v[0];
        csum += thresh;
        LL ans = abs(v[0] - thresh);
        for (int i = n - 1; i > 0 && csum > k; i--)
            ans++,
                csum -= v[i], csum += thresh;
        cost = min(cost, ans);
    }
    for (LL y = 1; y <= n - 1; y++)
    {
        double K = k, my = m[y], Y = y;
        double f = (K - my) / (Y + 1.0);
        f = floor(f);
        LL x = f;
        LL ccst;
        if (x <= v[0])
            ccst = (v[0] - x) + y;
        else
            ccst = y;
        // cout << y << " " << x << " " << ccst << endl;
        cost = min(cost, ccst);
    }
    cout << max(0ll, cost) << endl;
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