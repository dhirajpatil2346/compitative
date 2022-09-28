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
        n += n;
        string s = " ";
        string j;
        cin >> j;
        s += j;
        cout << s << endl;
        int in = 0, out = 0;
        vector<int> inc(n + 2), outc(n + 2);
        for (int i = 1; i <= n; i++)
        {
            inc[i] = in, outc[i] = out;
            if (s[i] == '(')
            {
                in++;
            }
            else
            {
                out++;
            }
        }
        inc[n + 1] = in, outc[n + 1] = out;
        vector<vector<int>> v(n + 1);
        /*
        for(auto &val:inc)
        {
            cout<<val<<" ";
        }
        cout<<endl;
        for(auto &val:outc)
        {
            cout<<val<<" ";
        }
        cout<<endl;
        */
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == ')')
            {
                continue;
            }
            for (int j = i + 1; j <= n; j++)
            {
                int inb = inc[j + 1] - inc[i];
                int clb = outc[j + 1] - outc[i];
                if (inb == clb)
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
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