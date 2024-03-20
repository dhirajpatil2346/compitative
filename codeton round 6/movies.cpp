#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int f(int ind, vector<pair<int, int>> &vp, vector<int> &dp)
{
    if (ind >= vp.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int ret = f(ind + 1, vp, dp);
    int it = upper_bound(vp.begin(), vp.end(), vp[ind].second) - vp.begin();
    return dp[ind] = max(ret, 1 + f(it, vp, dp));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int, vector<int>> m;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        m[x].push_back(y);
        vp[i].first = x, vp[i].second = y;
    }
    sort(vp.begin(), vp.end());
    vector<int> dp(n, -1);
    cout << f(0, vp, dp) << endl;
    return 0;
}