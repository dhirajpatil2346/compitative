#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> g[N];
vector<bool> vis(N);
vector<int> sum(N, 0);
void dfs(int source, int parent = -1)
{
    if (vis[source])
    {
        return;
    }
    vis[source] = true;
    sum[source] = 1;
    for (auto &child : g[source])
    {
        if (vis[child] || child == parent)
        {
            continue;
        }
        dfs(child, source);
        sum[source] += sum[child];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    dfs(1, -1);
    int ts = n;
    /*
    for(int i = 1 ; i <= n ; i++){ts+=i;}
     for(int  i = 1 ; i <= n ; i++)
     {
         cout<<i<<"  "<<sum[i]<<endl;
     }
     cout<<ts<<endl;
     */
    int maxi = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "    " << sum[i] << endl;
        maxi = max(maxi, (ts - sum[i]) * sum[i]);
    }
    cout << maxi << endl;
    return 0;
}