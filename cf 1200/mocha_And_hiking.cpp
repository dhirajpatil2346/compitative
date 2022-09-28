#include <bits/stdc++.h>
using namespace std;
bool got = false;
vector<int> path;
void dfs(int sc, vector<vector<int>> &v, vector<bool> vis, int n, vector<int> curr)
{
    if (got)
    {
        return;
    }
    vis[sc] = true;
    curr.push_back(sc);
    if (curr.size() == n + 1)
    {
        path = curr;
        got = true;
        return;
    }
    for (auto &val : v[sc])
    {
        if (vis[val])
        {
            continue;
        }
        dfs(val, v, vis, n, curr);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        got = false;
        int n;
        cin >> n;
        vector<vector<int>> v(n + 2);
        for (int i = 1; i <= n - 1; i++)
        {
            v[i].push_back(i + 1);
        }
        vector<bool> vis(n + 1);
        vector<int> curr;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                v[i].push_back(n + 1);
            }
            else
            {
                v[n + 1].push_back(i);
            }
        }
        /*
        for (int i = 1; i <= n + 1; i++)
        {
            cout << i << "  -->  ";
            for (auto &val : v[i])
            {
                cout << val << " ";
            }
            cout << endl;
        }
        */
        for (int i = 1; i <= n + 1; i++)
        {
            if (got)
            {
                break;
            }
            dfs(i, v, vis, n, curr);
        }
        for (auto &val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}