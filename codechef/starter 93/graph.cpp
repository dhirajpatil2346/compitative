#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void dfs(int sc, int cp, vector<vector<int>> &v, vector<int> &power)
{
    if (cp < 0)
        return;
    if (power[sc] >= cp)
        return;
    power[sc] = cp;
    for (auto &child : v[sc])
    {
        cout << sc << " " << child << " " << cp - 1 << endl;
        dfs(child, cp - 1, v, power);
    }
}
bool cmp(pair<int, int> p1, pair<int, int> p2) { return p1.first >= p2.first; }
void solve()
{
    LL n, m, k;
    cin >> n >> m >> k;
    vector<int> nodes(k), dist(k);
    vector<int> power(n + 1, -1);
    for (auto &val : nodes)
        cin >> val;
    // queue<int> q;
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; i++)
    {
        int y;
        cin >> y;
        if (power[nodes[i]] >= y)
            continue;
        power[nodes[i]] = y;
        power[nodes[i]]--;
        q.push({power[nodes[i]], nodes[i]});
    }
    vector<vector<int>>
        v(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    while (!q.empty())
    {
        auto p = q.top();
        int f = p.second;
        q.pop();
        // cout << "-->" << p.first << " " << p.second << endl;
        if (power[f] == 0)
            continue;
        for (auto &child : v[f])
        {
            if (power[child] >= power[f] - 1)
                continue;
            // cout << child << endl;
            power[child] = power[f] - 1;
            q.push({power[child], child});
        }
    }
    bool g = true;
    for (int i = 1; i <= n; i++)
        if (power[i] == -1)
            g = false;
    if (g)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
