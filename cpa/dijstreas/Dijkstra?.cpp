#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<pair<int, int>> g[N];
vector<long long> dist(N, 9223372036854775807);
vector<int> par(N);

void Dij(int source)
{
    set<pair<long long, int>> s;
    dist[source] = 0;
    s.insert({dist[source], source});
    vector<bool> vis(N, false);
    while (s.size() > 0)
    {
        pair<int, int> curr = *s.begin();
        s.erase(s.begin());
        int v = curr.second;
        long long v_wt = curr.first;
        if (vis[v])
        {
            continue;
        }
        vis[v] = true;
        for (auto &val : g[v])
        {
            int target_v = val.first;
            long long wt_to_add = val.second;
            if (dist[target_v] > dist[v] + wt_to_add)
            {
                par[target_v] = v;
                dist[target_v] = dist[v] + wt_to_add;
                s.insert({dist[target_v], target_v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    Dij(1);
    for (int i = 1; i <= n; i++)
    {
        // cout << i << "  " << dist[i] << endl;
    }
    int c = n;
    vector<int> ans;
    while (c != 0)
    {
        ans.push_back(c);
        c = par[c];
    }
    if (ans.size() == 0)
    {
        cout << -1 << endl;
    }
    else if(ans.size()==1 && ans[0]==n)
    {
        cout<<-1<<endl;
    }
    else
    {
        for (auto it = ans.rbegin(); it != ans.rend(); it++)
        {
            cout << *it << " ";
        }
    }
    return 0;
}