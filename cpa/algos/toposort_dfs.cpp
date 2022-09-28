#include <bits/stdc++.h>
using namespace std;
stack<int> topo;
void toposort(int source, vector<vector<int>> &v, vector<bool> &vis)
{
    vis[source] = true;
    for (auto &child : v[source])
    {
        if (vis[child])
        {
            continue;
        }
        toposort(child, v, vis);
        topo.push(child);
        // cout<<topo.top();
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    vector<bool> vis(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        toposort(i, v, vis);
        topo.push(i);
    }
    vector<int> ans;
    while (!topo.empty())
    {
        ans.push_back(topo.top());
        topo.pop();
    }
    for (auto &val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}