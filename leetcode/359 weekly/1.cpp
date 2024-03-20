#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> q;
    vector<int> track(n + 1);
    set<int> v[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
    }
    for (int i = 1; i <= n; i++)
        track[i] = v[i].size();
    for (int i = 1; i <= n; i++)
        q.insert({v[i].size(), i});
    // precomputation is done and graph is prepared
    int op = 0;
    vector<int> ans;
    vector<bool> vis(n + 1, false);
    while (q.size())
    {
        auto f = *q.rbegin();
        q.erase(prev(q.end()));
        if ((vis[(int)f.first]) && (f.second == 0))
            continue;
        int pt = f.second;
        vis[pt] = true;
        ans.push_back(pt);
        // remove all edges of pt
        for (auto &child : v[pt])
            v[child].erase(v[child].find(pt));
        // collect its childs, remove them as well and remove their connections and update accordingly
        for (auto &child : v[pt])
        {
            for(auto &gs:v[child])
            {
                
            }
        }
        for (auto &child : v[pt])
        {
            int gs = child;
            q.erase(q.find({track[gs], gs}));
            track[gs] = v[gs].size();
            q.insert({track[gs], gs});
        }
    }
    cout << ans.size() << endl;
    if (ans.size())
    {
        for (auto &val : ans)
            cout << val << " ";
        cout << endl;
    }
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
1 2
2 3
3 3
4 3
5 3
6 2

remove 2 and its colligues
1 4 are remaining
remove 1


*/