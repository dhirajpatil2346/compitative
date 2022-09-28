#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 1;
const int lg = 18;
vector<int> graph[N];
vector<int> dp[N];
vector<bool> vis(N);
vector<int> depth(N);
vector<int> parent(N, -1);

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
    for (auto &val : graph[source])
    {
        if (vis[val])
        {
            continue;
        }
        dep++;
        parent[val] = source;
        dfs(val, dep);
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
        for (int h = 1; h <= lg; h++)
        {
            if (dp[i][h - 1] != -1)
            {
                dp[i][h] = dp[dp[i][h - 1]][h - 1];
            }
        }
    }
}

int kth(int pt, int anc)
{
    int c = pt, curr_level = anc;
    for (int i = lg; i >= 0; i--)
    {
        if (dp[c][i] != -1 && (1 << i) <= curr_level)
        {
            c = dp[c][i];
            curr_level -= (1 << i);
        }
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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