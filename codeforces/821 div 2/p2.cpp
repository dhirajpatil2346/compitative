#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if (m < 1 && k < 1)
        {
            cout << -1 << endl;
        }
        else
        {
            int z = max(m, k);
            int win = z;
            if ((n - 1) % z == 0)
            {
                for (int i = 1; i <= n; i += z, i++)
                {
                    int f = z;
                    while (f--)
                    {
                        cout << i << " ";
                    }
                }
                cout << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}