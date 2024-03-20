#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> org(n);
    for (auto &val : org)
        cin >> val;
    vector<LL> v = org, pre = org;
    sort(v.begin(), v.end());
    sort(pre.begin(), pre.end());
    for (int i = 1; i < n; i++)
        pre[i] += pre[i - 1];
    // for (auto &val : pre)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : org)
    //     cout << val << " ";
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        int pos = upper_bound(v.begin(), v.end(), org[i]) - v.begin() - 1;
        LL left = pos + 1;
        LL right = n - left;
        LL leftsum = pre[pos];
        LL rightsum = pre.back() - leftsum;
        // cout << i << " " << org[i] << " " << left << " " << leftsum << " " << right << " " << rightsum << endl;
        LL ans = n + left * org[i] - leftsum + rightsum - (right * org[i]);
        cout << ans << " ";
    }
    cout << endl;
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