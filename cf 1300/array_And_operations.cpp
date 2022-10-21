#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    vector<bool> vis(n);
    sort(v.begin(), v.end());
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    int sc = 0;
    for (int i = 0; i < n; i++)
    {
        if (m == 0)
        {
            break;
        }
        if (vis[i])
        {
            continue;
        }
        m--;
        cout << i << endl;
        bool got = false;
        for (int j = i + 1; j < n; j++)
        {
            cout << "     " << j << endl;
            if (vis[j])
            {
                continue;
            }
            if ((v[i] / v[j]) == 0)
            {
                vis[j] = true;
                v[i] = 0, v[j] = 0;
                vis[i] = true;
                got = true;
                break;
            }
        }
        if (got)
        {
            continue;
        }
        for (int k = i + 1; k < n; k++)
        {
            if (vis[k])
            {
                continue;
            }
            vis[k] = true;
            vis[i] = true;
            sc += min(v[k] / v[i], v[i] / v[k]);
            v[i] = 0, v[k] = 0;
            break;
        }
    }
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << accumulate(v.begin(), v.end(), 0) + sc << endl;
    return 0;
}