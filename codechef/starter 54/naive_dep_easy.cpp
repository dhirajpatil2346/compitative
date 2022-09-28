#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph(n);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bool next_present = true;
    int next = 1;
    vector<int> parent_dep(n + 1);
    vector<int> leader;
    int i = 0;
    leader.push_back(1);
    while (i != leader.size())
    {
        vector<bool> vis(n + 1);
        int init_ele = graph[leader[i]].size();
        for (auto &val : graph[leader[i]])
        {
            if(graph[val].size())
        }

        i++;
    }
    return 0;
}