#include <bits/stdc++.h>
using namespace std;
const int N = 7;
const int lg = 4;

int log(int n)
{
    int c = 1;
    while (n /= 2)
    {
        c++;
    }
    return c;
}

int lca(int a, int b, int level[], int dp[][lg], int parent)
{
    int LG;

    if (level[a] < level[b])
    {
        swap(a, b);
    }
    for (int LG = 0; (1 << LG) <= level[a]; LG++)
        ;

    for (int i = LG - 1; i >= 0; i--)
    {
        if ((level[a] - (1 << i)) >= level[b])
        {
            a = dp[a][i];
        }
    }
    if (a == b)
    {
        cout << "lca of a and b is : " << a << endl;
        return a;
    }

        for(int i = LG; i>=0;i--)
        {
            if(dp[i][h-1] != dp[i][h-1])
            {
                
            }
        }
}

void findKth(int a, int k, int dp[][lg])
{
    int c = a;
    int curr_level = k;
    for (int i = lg; i >= 0; i--)
    {
        if (dp[c][i] != -1 && (1 << i) <= curr_level)
        {
            cout << c << "  " << i << endl;
            c = dp[c][i];
            curr_level = curr_level - (1 << i);
        }
    }
    cout << "the " << k << "th ancestorm of " << a
         << " is " << c << endl;
}

void dfs(int s, vector<vector<int>> &graph, int &depth, vector<int> &parent, vector<int> &level, vector<bool> &vis)
{
    vis[s] = true;
    level[s] = depth;
    for (auto child : graph[s])
    {
        if (vis[child])
        {
            continue;
        }
        depth++;
        dfs(child, graph, depth, parent, level, vis);
        parent[child] = s;
        depth--;
    }
}

void prec(int dp[N][lg], vector<int> parent)
{
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = parent[i];
    }
    for (int h = 1; h < lg; h++)
    {
        /*
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < lg; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
        */
        for (int i = 0; i < N; i++)
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    int dp[n][lg];
    vector<bool> vis(n, false);
    vector<int> level(n, 0);
    vector<int> parent(n, 0);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    int depth = 0;
    dfs(0, graph, depth, parent, level, vis);
    prec(dp, parent);
    findKth(6, 5, dp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < lg; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}