#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
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
    set<int> q;
    vector<bool> vis(n + 1, false);
    q.insert(1);
    while (q.size())
    {
        int f = *q.begin();
        q.erase(q.begin());
        if (vis[f])
            continue;
        vis[f] = true;
        cout << f << " ";
        for (auto child : v[f])
            q.insert(child);
    }
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