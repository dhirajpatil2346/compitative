#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n + 1);
        for (int i = 0; i <= n; i++)
        {
            v[i] = v[i + 1];
        }
        vector<pair<int, int>> p;
        vector<bool> vis(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            int x = i, y = -1;
            bool f1=false,f2=false;
            for (int j = 1; j <= n; j++)
            {
                if (i == j || vis[j])
                {
                    continue;
                }
                int c = (x + k) * j;
                int d = (j+k)*i;
                // cout<<i<<j<<d<<endl;
                if (c % 4 == 0)
                {
                    f1=true;
                    y = j;
                    break;
                }
                else if(d%4==0)
                {
                    f2=true;
                    y = j;
                    break;
                }
            }
            if (f1 && y != -1)
            {
                p.push_back({x, y});
                vis[x] = true;
                vis[y] = true;
            }
            if(f2&& y!=-1)
            {
                // cout<<y<<x<<endl;
                p.push_back({y, x});
                vis[x] = true;
                vis[y] = true;
            }
        }
        if (p.size() == 0 || 2*p.size()!=n)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (auto &val : p)
            {
                cout << val.first << " " << val.second << endl;
            }
        }
    }
    return 0;
}