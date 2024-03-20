#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    vector<pair<int, int>> vp;
    for (auto &val : m)
        vp.push_back({val.second, val.first});
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    vector<vector<int>> v(vp[0].first);
    int i = 0;
    int j = 0;
    int x = 0;
    while (i < vp.size() && vp[i].first == vp[0].first)
    {
        for (int k = 0; k < vp[i].first; k++)
            v[k].push_back(vp[i].second);
        i++;
    }
    int z = v.size() - 1;
    vector<int> extra;
    while (i < vp.size())
    {
        for (int k = 0; k < vp[i].first; k++)
        {
            v[j].push_back(vp[i].second);
            j++;
            j %= (z);
        }
        i++;
    }
    vector<int> ans;
    for (auto &val : v)
        for (auto &valu : val)
        {
            ans.push_back(valu);
        }
    map<int, vector<int>> track;
    for (int i = 0; i < ans.size(); i++)
        track[ans[i]].push_back(i);
    int an = n;
    for (auto &val : track)
    {
        for (int i = 1; i < val.second.size(); i++)
            an = min(an, val.second[i] - val.second[i - 1] - 1);
    }
    cout << an << endl;
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
/*
4 3 2 4 3 2 4 3 1 4
*/