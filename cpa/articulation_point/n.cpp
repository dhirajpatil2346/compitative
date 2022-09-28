#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int timer = 0;
void dfs(int sc, vector<vector<int>> &v, vector<bool> &vis, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<int> &atp, int par = -1)
{
    parent[sc] = par;
    vis[sc] = true;
    timer++;
    disc[sc] = timer;
    low[sc] = timer;
    int c = 0;
    for (auto &val : v[sc])
    {
        // //cout << val << endl;
        if (val == par)
        {
            continue;
        }
        else if (vis[val])
        {
            // back-edge
            // cout << val << " " << sc << endl;
            low[sc] = min(low[sc], disc[val]);
        }
        else
        {
            // //cout<<val<<endl;
            c++;

            dfs(val, v, vis, disc, low, parent, atp, sc);
            low[sc] = min(low[val], low[sc]);
            if (sc == 7)
            {
                // cout<<sc<<"  "<<val<<endl;
            }
            if (disc[sc] <= low[val] && parent[sc] != -1)
            {
                atp.push_back(sc);
            }
            if (parent[val] == -1 && c > 1)
            {
                atp.push_back(sc);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        timer = 0;
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(n + 1);
        vector<bool> vis(n + 1);
        vector<int> disc(n + 1);
        vector<int> low(n + 1);
        vector<int> parent(n + 1, -1);
        vector<int> atp;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int sc = 1;
        dfs(sc, v, vis, disc, low, parent, atp);
        map<int, bool> um;
        for (auto &val : atp)
        {
            um[val] = true;
        }

        // check alone players
        if (atp.size())
        {
            for (int i = 1; i <= n; i++)
            {
                bool isP = true;
                if (v[i].size() < 2)
                {
                    continue;
                }
                for (auto &val : v[i])
                {

                    if (!um[val])
                    {
                        isP = false;
                    }
                }
                if (isP)
                {
                    atp.push_back(i);
                }
            }
        }
        if (atp.size() == 0)
        {
            atp.push_back(sc);
            um[atp[0]] = true;
        }
        vector<int> leaders(atp.size() + 1);
        int i = 1;
        for (auto &val : atp)
        {
            leaders[i++] = val;
        }

        vector<int> owner(n + 1);
        i = 1;
        for (auto &val : atp)
        {
            owner[val] = i;
            for (auto &val : v[val])
            {
                if (um[val])
                {
                    continue;
                }
                owner[val] = i;
            }
            i++;
        }

        // o/p
        cout << atp.size() << endl;
        for (int i = 1; i < n + 1; i++)
        {
            cout << owner[i] << " ";
        }
        cout << endl;
        for (auto &val : atp)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
    for (int i = 0; i < n + 1; i++)
    {
        //cout << i << " --> ";
        for (auto &val : v[i])
        {
            //cout << val << " ";
        }
        //cout << endl;
    }
    */
/*
    for (int i = 0; i < n + 1; i++)
    {
        //cout << i << " ";
    }
    //cout << endl;
    for (int i = 0; i < n + 1; i++)
    {
        //cout << parent[i] << " ";
    }
    //cout << endl;
    for (int i = 0; i < n + 1; i++)
    {
        //cout << disc[i] << " ";
    }
    //cout << endl;
    for (int i = 0; i < n + 1; i++)
    {
        //cout << low[i] << " ";
    }
    //cout << endl;

    for (auto &val : atp)
    {
        //cout << val << " ";
    }
    //cout << endl;
    */
/*
        0  --- 1
        | \    |
        |   \  |
        3     \2
        |
        |
        4
        |
        |
        5

 1(1/1)   ------   3(3/3)
    \           /
      \        /
         2(2/2)
          |      \
          |         \
         4(4/4) ---  6(6/6)
          |           |
          |           |
         5(5/5)      7(7/7)
*/