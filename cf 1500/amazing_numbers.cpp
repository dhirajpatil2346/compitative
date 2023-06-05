#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<int> ans(n, 1e9);
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(v[i]) == m.end())
            m[v[i]].push_back(-1);
        m[v[i]].push_back(i);
    }
    for (auto &val : m)
        val.second.push_back(n);
    // for (auto &val : m)
    // {
    //     cout << val.first << " -->  :  ";
    //     for (auto &valu : val.second)
    //         cout << valu << " ";
    //     cout << endl;
    // }
    for (auto &val : m)
    {
        int maxi = -1;
        for (int i = 1; i < val.second.size(); i++)
        {
            maxi = max(maxi, val.second[i] - val.second[i - 1]);
        }
        ans[maxi - 1] = min(ans[maxi - 1], val.first);
    }
    for (int i = 1; i < n; i++)
        ans[i] = min(ans[i], ans[i - 1]);
    for (auto &val : ans)
        if (val == 1e9)
            val = -1;
    for (auto &val : ans)
        cout << val << " ";
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