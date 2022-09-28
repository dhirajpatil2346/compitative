#include <bits/stdc++.h>
using namespace std;

void dfs(int daughter, vector<vector<int>> &v, vector<bool> &md, vector<bool> &mp)
{
    if (md[daughter])
    {
        return;
    }
    for (auto &val : v[daughter])
    {
        if (mp[val])
        {
            continue;
        }
        mp[val] = true;
        md[daughter] = true;
        break;
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
        vector<vector<int>> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;
            while (k--)
            {
                int x;
                cin >> x;
                v[i].push_back(x);
            }
        }
        vector<bool> md(n + 1);
        vector<bool> mp(n + 1);
        md[0] = true;
        md[0] = true;
        for (int i = 1; i <= n; i++)
        {
            dfs(i, v, md, mp);
        }
        vector<int> p1, p2;
        int c = 0;
        for (auto i = 1; i <= n; i++)
        {
            if (!md[i])
            {
                p1.push_back(i);
            }
        }
        for (auto i = 1; i <= n; i++)
        {
            if (!mp[i])
            {
                p2.push_back(i);
                c++;
            }
        }
        if (p1.size())
        {
            cout << "IMPROVE"<<endl;
            for (int i = 0; i < 1; i++)
            {
                cout << p1[i] << " " << p2[i] << endl;
            }
        }
        else
        {
            cout << "OPTIMAL" << endl;
        }
    }
    return 0;
}