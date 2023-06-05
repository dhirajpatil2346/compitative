#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    vector<LL> p = v;
    for (int i = 1; i < n; i++)
        p[i] += p[i - 1];
    // for (auto &val : p)
    //     cout << val << " ";
    // cout << endl;
    vector<LL> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] += p[i];
        if ((i - k) >= 0)
            dp[i] -= p[i - k];
        if ((i - k) >= 0)
            dp[i] += 2 * dp[i - k];
        if ((i - 2 * k) >= 0)
            dp[i] -= dp[i - 2 * k];
    }
    for (auto &val : dp)
        cout << val << " ";
    cout << endl;
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