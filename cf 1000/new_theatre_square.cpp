#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ans = 0;
        float z = (float)y / 2;
        if (x <= z)
        {
            // follow x
            for (auto &val : v)
            {
                string s = val;
                for (int i = 0; i < m; i++)
                {
                    if (s[i] == '*')
                    {
                        continue;
                    }
                    ans += x;
                }
            }
        }
        else
        {
            // use first 1*2 then 1*1
            for (auto &val : v)
            {
                for (int i = 0; i < m; i++)
                {
                    string s = val;
                    if (s[i] == '*')
                    {
                        continue;
                    }
                    if (i == m - 1)
                    {
                        ans += x;
                        continue;
                    }
                    else if (s[i] == '.' && s[i + 1] == '.')
                    {
                        ans += y;
                        i++;
                        continue;
                    }
                    ans += x;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}