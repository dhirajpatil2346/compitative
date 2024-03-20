#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0, b = 0;
    int t;
    cin >> t;
    for (int u = 0; u < t; u++)
    {
        int i, x, y;
        cin >> i >> x >> y;
        if (x == y)
        {
            cout << "YES" << endl;
            a = x, b = y;
            continue;
        }
        if (i == 1)
        {
            cout << "YES" << endl;
            a = x, b = y;
            continue;
        }
        else
        {
            if ((x >= a && y >= b) && (x >= b && y >= a))
            {
                cout << "NO" << endl;
                continue;
            }
            else
            {
                cout << "YES" << endl;
                if (x >= a && y >= b)
                {
                    a = x, b = y;
                }
                else
                {
                    a = y, b = x;
                }
            }
        }
    }
    return 0;
}