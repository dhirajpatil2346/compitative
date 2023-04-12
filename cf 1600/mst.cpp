// C++ Program to find weight of
// minimum spanning tree in a
// complete graph where edges
// have weight either 0 or 1
#include <bits/stdc++.h>
using namespace std;

// To store the edges of the given
// graph
map<int, int> g[200005];
set<int> s, ns;

// A utility function to perform
// DFS Traversal
void dfs(int x)
{
    vector<int> v;
    v.clear();
    ns.clear();

    // Check those vertices which
    // are stored in the set
    for (int it : s)
    {
        // Vertices are included if
        // the weight of edge is 0
        if (!g[x][it])
        {
            v.push_back(it);
        }
        else
        {
            ns.insert(it);
        }
    }
    s = ns;
    for (int i : v)
    {
        dfs(i);
    }
}

// A utility function to find the
// weight of Minimum Spanning Tree
void weightOfMST(int N)
{
    // To count the connected
    // components
    int cnt = 0;

    // Inserting the initial vertices
    // in the set
    for (int i = 1; i <= N; ++i)
    {
        s.insert(i);
    }

    // Traversing vertices stored in
    // the set and Run DFS Traversal
    // for each vertices
    for (; s.size();)
    {

        // Incrementing the zero
        // weight connected components
        ++cnt;

        int t = *s.begin();
        s.erase(t);

        // DFS Traversal for every
        // vertex remove
        dfs(t);
    }

    cout << cnt - 1;
}

// Driver's Code
int main()
{
    int N = 6, M = 11;
    
    int edges[][M] = {{1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 4}, {3, 5}, {3, 6}};

    // Insert edges
    for (int i = 0; i < M; ++i)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        g[u][v] = 1;
        g[v][u] = 1;
    }

    // Function call find the weight
    // of Minimum Spanning Tree
    weightOfMST(N);
    return 0;
}