#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> g[N];
vector<bool> vis(N);

void dfs(int source, int parent)
{
    if(vis[source])
    {return;}
    vis[source]=true;
    // cout<<source<<endl;
    for(auto &val:g[source])
    {
        if(val==parent || vis[val]){continue;}
        dfs(val,source);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int c = 0;
    for (int i = 0; i < m ; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(vis[i]){continue;}
        c++;
        dfs(i,-1);
    }
    cout<<c<<endl;
    return 0;
}