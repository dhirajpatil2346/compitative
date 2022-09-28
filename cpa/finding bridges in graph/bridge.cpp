#include <bits/stdc++.h>
using namespace std;

void findBridge(vector<vector<int>> &v, int timer, int source, int parent, vector<bool> &vis,
                vector<int> &low, vector<pair<int, int>> &result, vector<int> &timing)
{
    vis[source] = true;
    timing[source] = timer;
    low[source] = timer++;
    for (auto &nbr : v[source])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (vis[nbr])
        {
            // back-edge
            low[source] = min(low[source], low[nbr]);
        }
        else
        {
            findBridge(v, timer, nbr, source, vis, low, result, timing);
            low[source] = min(low[source], low[nbr]);

            // check if its a bridge

            if (low[nbr] > timing[source])
            {
                result.push_back({source, nbr});
            }
        }
    }
}

int main()
{
    // create graph
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int timer = 0;
    // create various arrays like timing, low, visited
    vector<int> timing(n, -1);
    vector<int> low(n, -1);
    vector<bool> vis(n, false);

    // create result vector of pairs
    vector<pair<int, int>> result;

    // run findbridge function
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            findBridge(v, timer, i, -1, vis, low, result, timing);
        }
    }

    for (auto &val : result)
    {
        cout << val.first << "  " << val.second << endl;
    }
    return 0;
}