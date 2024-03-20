#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    vector<vector<LL>> v;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<LL> nv(m);
        for (auto &val : nv)
            cin >> val;
        sort(nv.begin(), nv.end());
        v.push_back(nv);
    }
    LL mini = INT_MAX;
    for (int i = 0; i < n; i++)
        mini = min(mini, v[i][0]);
    set<int> minis;
    for (int i = 0; i < n; i++)
        if (v[i][0] == mini)
            minis.insert(i);
    LL ans = (mini);
    vector<LL> ansval;
    for (int i = 0; i < n; i++)
        ansval.push_back(v[i][1]);
    sort(ansval.begin(), ansval.end());
    ans += accumulate(ansval.begin(), ansval.end(), 0ll);
    ans -= ansval[0];
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