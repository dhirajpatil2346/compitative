#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int j = y;
        for (int i = -1000; i <= j; i++)
        {
            int k = 3 * x - (i + j);
            if (k >= -1000 && k <= 1000)
            {
                cout << i << " " << j << " " << k << endl;
                break;
            }
        }
    }
    return 0;
}