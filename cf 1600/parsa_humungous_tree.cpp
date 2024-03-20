#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL f(int sc, int pa, int parent, vector<vector<int>> &v, vector<pair<LL, LL>> &vp, vector<int> &par, vector<vector<LL>> &dp)
{
    LL ret = 0;
    if (dp[sc][pa] != -1)
        return dp[sc][pa];
    if (pa == 0)
    {
        LL c = 0;
        for (auto &child : v[sc])
            if (child != parent)
                c += f(child, 1, sc, v, vp, par, dp);
        LL d = 0;
        for (auto &child : v[sc])
            if (child != parent)
                d += f(child, 2, sc, v, vp, par, dp);
        c = max(c, d);
        ret = max(ret, c);
    }
    else if (pa == 1)
    {
        LL c = 0;
        c += abs(vp[par[sc]].first - vp[sc].first);
        for (auto &child : v[sc])
            if (child != parent)
                c += f(child, 1, sc, v, vp, par, dp);
        LL d = 0;
        d += abs(vp[par[sc]].first - vp[sc].second);
        for (auto &child : v[sc])
            if (child != parent)
                d += f(child, 2, sc, v, vp, par, dp);
        c = max(c, d);
        ret = max(ret, c);
    }
    else if (pa == 2)
    {
        LL c = 0;
        c += abs(vp[par[sc]].second - vp[sc].first);
        for (auto &child : v[sc])
            if (child != parent)
                c += f(child, 1, sc, v, vp, par, dp);
        LL d = 0;
        d += abs(vp[par[sc]].second - vp[sc].second);
        for (auto &child : v[sc])
            if (child != parent)
                d += f(child, 2, sc, v, vp, par, dp);
        c = max(c, d);
        ret = max(ret, c);
    }
    return dp[sc][pa] = ret;
}

void dfs(int sc, int parent, vector<vector<int>> &v, vector<bool> &vis, vector<int> &par)
{
    if (vis[sc])
        return;
    vis[sc] = true;
    par[sc] = parent;
    for (auto &child : v[sc])
        dfs(child, sc, v, vis, par);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<pair<LL, LL>> vp(n + 1, {0, 0});
    vector<int> par(n + 1, -1);
    for (int i = 1; i <= n; i++)
        cin >> vp[i].first >> vp[i].second;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int sc = 1;
    vector<bool> vis(n + 1, false);
    dfs(sc, 0, v, vis, par);
    LL ans = 0;
    vector<vector<LL>> dp(n + 1, vector<LL>(4, -1));
    ans = f(sc, 0, 0, v, vp, par, dp);
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