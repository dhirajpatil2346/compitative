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
        int z = n;
        int k = 0;
        while (z != 0)
        {
            int c = 1;
            while (true)
            {
                if (2 * c > z)
                {
                    break;
                }
                else
                {
                    c *= 2;
                }
            }
            k++;
            z -= c;
        }
        if (k == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << k - 1 << endl;
        }
    }
    return 0;
}