#include <bits/stdc++.h>
using namespace std;

void topobfs(int source, vector<vector<int>> &v, vector<int> &inc)
{
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << endl;
        for (auto &nbr : v[curr])
        {
            inc[nbr]--;
            if (inc[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    vector<int> inc(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        inc[y]++;
    }
    int source = 0;
    for (int i = 0; i < n; i++)
    {
        if (inc[i] == 0)
        {
            source = i;
            break;
        }
    }
    topobfs(source, v, inc);
    return 0;
}

/*
6 7
0 1
0 2
2 3
1 3
3 4
3 5
4 5
0 2 1 3 4 5
*/