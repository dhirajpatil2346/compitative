#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n), h(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : h)
        cin >> val;
    vector<bool> can(n, false);
    if (a.back() <= k)
        can.back() = true;
    for (int i = 0; i < n - 1; i++)
        if ((h[i] % h[i + 1]) == 0)
            if (a[i] <= k)
                can[i] = true;
    LL ans = 1;
    if (*min_element(a.begin(), a.end()) > k)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!can[i])
            continue;
        vector<LL> curr;
        while (i < n && can[i])
            curr.push_back(a[i++]);
        if (i < n)
            if (a[i] <= k)
                curr.push_back(a[i]);
        for (int j = 1; j < curr.size(); j++)
            curr[j] += curr[j - 1];
        // bin search is supposed to be used
        for (int j = 0; j < curr.size(); j++)
        {
            LL bc = 0;
            if (j > 0)
                bc = curr[j - 1];
            LL pos = upper_bound(curr.begin(), curr.end(), k + bc) - curr.begin() - 1ll;
            LL c = pos - j + 1;
            ans = max(ans, c);
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