#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<pair<int, int>> v[N];
vector<bool> vis(N);
vector<int> cost(N, INT_MAX);
int n, e;
int bfs()
{
    deque<int> q;
    q.push_back(1);
    cost[1] = 0;
    while (!q.empty())
    {
        auto front = q.front();
        q.pop_front();
        for (auto &val : v[front])
        {
            if (val.second == 0)
            {
                if (cost[val.first] > cost[front])
                {
                    cost[val.first] = cost[front];
                    q.push_front(val.first);
                }
            }
            else
            {
                if (cost[val.first] > cost[front] + 1)
                {
                    q.push_back(val.first);
                    cost[val.first] = cost[front]+1;
                }
            }
        }
    }

    return (cost[n] == INT_MAX) ? -1 : cost[n];
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back({y, 0});
        v[y].push_back({x, 1});
    }
/*
    for (int i = 1; i <= n; i++)
    {
        cout << i << "  -->  ";
        for (auto &val : v[i])
        {
            cout << val.first << "  " << val.second << endl;
        }
    }
*/
    cout << bfs();
    return 0;
}