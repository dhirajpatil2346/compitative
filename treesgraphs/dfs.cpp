/*
10 9
1 2
1 3
1 4
3 5
4 6
4 7
7 8
7 9
7 10
*/

#include <bits/stdc++.h>
using namespace std;

#define N 50
bool vis[N] = {false};
vector<int> v[N];
vector<int> depth(N), height(N);
void dfs(int source, int par = -1)
{
    vis[source] = true;
    for (auto child : v[source])
    {
        if(vis[child]){continue;}
        if (child == par)
        {
            continue;
        }
    cout << child << " ";

        depth[child] = depth[source] + 1;
        dfs(child, source);
        height[source] = max(height[source], height[child] + 1);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << "dfs is ";
    dfs(5);
    cout << endl;
    /*
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << depth[i] << " " << height[i] << endl;
    }
*/
    return 0;
}