#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL dfs(LL sc, vector<bool> &vis, vector<multiset<pair<LL, LL>>> &v)
{
    if (vis[sc])
        return 0ll;
    vis[sc] = true;
    LL ret = 0;
    while (v[sc].size())
    {

        auto val = *(prev(v[sc].end()));
        if (!vis[val.second])
            ret += (val.first + dfs(val.second, vis, v));
        v[sc].erase(prev(v[sc].end()));
    }
    return ret;
}
void solve()
{
    int n, p;
    cin >> n >> p;
    vector<multiset<pair<LL, LL>>> v(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < p; i++)
    {
        LL a, b, c;
        cin >> a >> b >> c;
        v[a].insert({c, b});
        v[b].insert({c, a});
    }
    LL sc = 1;
    cout << dfs(sc, vis, v);
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