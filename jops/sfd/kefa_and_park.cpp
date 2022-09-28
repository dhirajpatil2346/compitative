#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/580/C
using namespace std;
int ans = 0;
vector<bool> vis(100007);
vector<int> t[100007];
vector<int> cat(100007);
void dfs(int m, int source, int parent, int cats)
{
    if (vis[source])
    {
        return;
    }
    if (cats > m)
    {
        return;
    }
    if (t[source].size() == 1  && source>1)
    {
        ans++;
    }
    vis[source] = true;
    for (auto &child : t[source])
    {
        //cout<<child<<endl;
        if (child == parent || vis[child])
        {
            continue;
        }
        if (cat[child] == 0)
        {
            dfs(m, child, source,0);
        }
        else
        {
            dfs(m, child, source, cats + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    vector<bool>vis(n+1);
    dfs(m,1,-1,cat[1]);
    cout << ans << endl;
    return 0;
}