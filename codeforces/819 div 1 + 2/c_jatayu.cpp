#include <bits/stdc++.h>
using namespace std;

void dfs(int sc, vector<vector<int>> &v, vector<bool> &vis)
{
    vis[sc] = true;
    for (auto &child : v[sc])
    {
        if (vis[child])
        {
            continue;
        }
        dfs(child, v, vis);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        n *= 2;
        vector<vector<int>> v(n + 1);
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] == '(')
                {
                    continue;
                }
                else if ((j - i - 1) % 2 == 0)
                {
                    v[i + 1].push_back(j + 1);
                    v[j + 1].push_back(i + 1);
                }
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            cout << i << " --> ";
            for (auto &val : v[i])
            {
                cout << val << " ";
            }
            cout << endl;
        }
        
        vector<bool> vis(n + 1);
        int c = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            dfs(i, v, vis);
            c++;
        }
        cout << c << endl;
    }
    return 0;
}