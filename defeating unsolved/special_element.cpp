#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    LL maxi = *max_element(v.begin(), v.end());
    sort(v.begin(), v.end());
    vector<bool> dp(maxi + 1, false);
    map<int, bool> fixed;
    dp[0] = true;
    for (int i = 0; i < dp.size(); i++)
    // if(m.find())
        if ((i - v[i]) > 0)
            dp[i] = dp[i - v[i]];
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