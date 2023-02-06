#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 2)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
            continue;
        }
        else if (n == 4)
        {
            cout << "2 4 1 3" << endl;
            continue;
        }
        vector<bool> vis(n + 1);
        int inc = (n - 1) / 2;
        vis[0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            for (int j = i; j <= n; j += inc)
            {
                if (vis[j])
                {
                    continue;
                }
                vis[j] = true;
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}