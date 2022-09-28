#include <bits/stdc++.h>
using namespace std;

int main()
{
    // take input
    int n, k; // n = no. of nodes // k = no. of edges
    cin >> n >> k;

    // create graph
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    // find ends
    vector<int> ends;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            ends.push_back(i);
        }
    }
/*
    for (int i = 0; i < n + 1; i++)
    {
        cout << i << " --> ";
        for (auto &val : graph[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }

    for (auto &val : ends)
    {
        cout << val << " ";
    }
    cout << endl;
*/
    /*
        // now no. of departments = no. of ends
        int no_of_departments = ends.size();

        // find departments and parent_department
        vector<int> departments[no_of_departments];
        vector<bool> vis(n + 1);
        vector<int> parent(n + 1);
        for (int i = 0; i < no_of_departments; i++)
        {
            int to_ieterate = ends[i];
            departments[i].push_back(to_ieterate);
            vis[to_ieterate] = true;
            parent[to_ieterate] = i;
            for (auto &val : graph[to_ieterate])
            {
                vis[val] = true;
                departments[i].push_back(val);
                parent[to_ieterate] = val;
            }
        }

        // find leader
        // steps
        // make new visted array for each dept
        // make visited using to_iterate int again
        // if someone has any value not visited then it's their leader
        vector<int> leader(no_of_departments);
        for (int i = 0; i < no_of_departments; i++)
        {
            vector<bool> vis(n + 1);
            for (auto &val : graph[ends[i]])
            {
                vis[val] = true;
            }
            for (auto &val : graph[ends[i]])
            {
                for (auto &valu : graph[val])
                {
                    if (!vis[valu])
                    {
                        leader[i] = valu;
                    }
                }
            }
        }
        for (int i = 0; i < n + 1; i++)
        {
            cout << leader[i] << endl;
        }
    */
    return 0;
}