#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
void makeVis(int x, int y, vector<bool> &vis)
{
    int i = x - 1, j = y - 1;
    for (int x = 0; x < int(vis.size()); x++)
    {
        vis[x][j] = true;
    }
    for (int x = 0; x < vis.size(); x++)
    {
        vis[x][j] = true;
    }
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<bool> col(n, true);
        vector<bool> row(n, true);
        vector<pair<int, int>> v;
        map<int, int> mr, mc;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            mr[x]++, mc[y]++;
            v.push_back({x, y});
            row[x] = false;
            col[y] = false;
        }
        bool rowf = false;
        bool colf = false;
        for (int i = 0; i < n; i++)
        {
            colf = colf || col[i];
        }
        for (int i = 0; i < n; i++)
        {
            rowf = rowf || row[i];
        }
        // bool gotrow = false;
        // bool gotcol = false;
        // for (auto &val : mr)
        // {
        //     if (val.second == 1)
        //     {
        //         gotrow = true;
        //     }
        // }
        // for (auto &val : mc)
        // {
        //     if (val.second == 1)
        //     {
        //         gotcol = true;
        //     }
        // }
        if (colf && rowf )
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}