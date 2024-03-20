#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void dfs(int sc, vector<vector<int>> &v, vector<int> &req, vector<int> &curr, vector<bool> &vis, vector<int> &ans)
{
    if (vis[sc])
        return;
    vis[sc] = true;
    ans.push_back(sc);
    for (auto &child : v[sc])
        curr[child]++;
    for (auto &child : v[sc])
    {
        if (vis[child] || (req[child] != curr[child]))
            continue;
        dfs(child, v, req, curr, vis, ans);
    }
}
bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<int> req(n + 1), curr(n + 1, 1);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        req[i] = x;
        mp[x].push_back(i);
    }
    vector<bool> vis(n + 1, false);
    vector<int> ans;
    for (auto &val : mp)
    {
        for (auto &valu : val.second)
        {
            if (vis[valu])
                continue;
            // cout << valu << " " << req[valu] << " " << curr[valu]<<" "<<vis[valu] << endl;
            if (req[valu] == curr[valu])
                dfs(valu, v, req, curr, vis, ans);
        }
    }
    if (ans.size() != n)
        return false;
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool f = solve();
    if (!f)
    {
        cout << -1 << endl;
    }
    return 0;
}