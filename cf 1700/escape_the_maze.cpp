#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> enemy;
    for (int i = 0; i < m; i++)
    {
        int u;
        cin >> u;
        enemy.insert(u);
    }
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if (m == 0)
    {
        cout << "YES" << endl;
        return;
    }
    vector<int> entime(n + 1, 1e7);
    set<pair<int, int>> s;
    for (auto &val : enemy)
    {
        entime[val] = 0;
        s.insert({0, val});
    }
    while (s.size())
    {
        auto f = *s.begin();
        s.erase(s.begin());
        int sc = f.second;
        int curr = f.first;
        for (auto &child : v[sc])
            if (entime[child] == 1e7)
            {
                entime[child] = curr + 1;
                s.insert({entime[child], child});
            }
    }
    vector<int> vissc(n + 1, 1e8);
    vissc[1] = 0;
    s.insert({0, 1});
    while (s.size())
    {
        auto f = *s.begin();
        s.erase(s.begin());
        int sc = f.second;
        int curr = f.first;
        for (auto &child : v[sc])
        {
            if (vissc[child] != 1e8)
                continue;
            int c = curr + 1;
            if (entime[child] <= c)
                continue;
            vissc[child] = c;
            s.insert({vissc[child], child});
        }
    }
    // for (auto &val : entime)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : vissc)
    //     cout << val << " ";
    // cout << endl;
    for (int i = 2; i <= n; i++)
    {
        if ((v[i].size() == 1) && (vissc[i] != 1e8))
        {
            cout << "YES" << endl;
            return;
        }
    }
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