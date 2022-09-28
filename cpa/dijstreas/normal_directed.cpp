/*
6 9
1 2 1
2 4 2
4 6 1
5 6 2
4 5 3
2 5 1
3 5 2
1 3 5
2 3 2

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

vector<pair<int, int>> edge_wt[N];
vector<bool> vis(N, false);
vector<int> wt(N, N);

void Dijstras(int source)
{
    set<pair<int, int>> q;
    wt[source] = 0;
    q.insert({0, source});
    while (q.size() > 0)
    {
        pair<int, int> curr_p = *q.begin();
        q.erase(q.begin());
        int q_wt = curr_p.first;
        int q_v = curr_p.second;
        // cout<<q_v<<"  "<<q_wt<<" --> "<<endl;
        if (vis[q_v])
        {
            continue;
        }
        vis[q_v] = true;
        for (auto &val : edge_wt[q_v])
        {
            int v_c = val.first;
            int c_wt = val.second;
            // cout<<v_c<<"            "<<c_wt<<endl;
            if (wt[q_v] + c_wt < wt[v_c])
            {
                wt[v_c] = wt[q_v] + c_wt;
                // cout<<"         "<<v_c<<"  ->  "<<wt[v_c]<<endl;
                q.insert({wt[v_c], v_c});
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
        edge_wt[x].push_back({y, z});
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto &val : edge_wt[i])
        {
            cout << i << "  "
                 << " --> " << val.first << " " << val.second << endl;
        }
    }
    Dijstras(1);
    for (int i = 1; i <= n; i++)
    {
        cout << i << "  " << wt[i] << endl;
    }

    return 0;
}