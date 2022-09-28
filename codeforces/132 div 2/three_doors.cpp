#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> v[i];
        }
        vector<bool> vis(3);
        for (int i = 0; i < 3; i++)
        {
            vis[i] = false;
        }
        int curr = n;
        while (curr != -1)
        {
            if (curr == 0 || vis[curr - 1])
            {
                curr = -1;
                break;
            }
            vis[curr - 1] = true;
            curr = v[curr - 1];
        }
        bool got = true;
        for (int i = 0; i < 3; i++)
        {
            if (vis[i] == false)
            {
                got = false;
                break;
            }
        }
        if (got)
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