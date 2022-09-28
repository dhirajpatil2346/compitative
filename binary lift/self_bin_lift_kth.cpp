#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int lg = 20;
vector<int> graph[N];
vector<int> dp[N];
vector<bool> vis(N);
vector<int> depth(N);
vector<int> parent(N, -1);
int kth(int pt, int anc)
{
    int c = pt, curr_level = anc;
    for (int i = lg; i >= 0; i--)
    {
        // cout<<c<<endl;
        if (dp[c][i] != -1 && (1 << i) <= curr_level)
        {
            c = dp[c][i];
            curr_level -= (1 << i);
        }
    }
    return c;
}
void Set()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= lg; j++)
        {
            dp[i].push_back(0);
        }
    }
}

void dfs(int source, int &dep)
{
    vis[source] = true;
    depth[source] = dep;
    dep++;
    for (auto &child : graph[source])
    {
        if (vis[child])
        {
            continue;
        }
        dfs(child, dep);
        parent[child] = source;
        dep--;
    }
}

void prec()
{
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = parent[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int h = 1; h < lg; h++)
        {
            if (dp[i][h - 1] != -1)
            {
                dp[i][h] = dp[dp[i][h - 1]][h - 1];
            }
        }
    }
}

int main()
{
    Set();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    int dep = 0;
    dfs(1, dep);
    prec();
    cout << kth(5, 2);
    return 0;
}