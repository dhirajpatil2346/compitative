#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long int n;
        cin >> n;
        long int j = n;
        int y = 0;

        while (true)
        {
            if (n > 4 * j)
            {
                cout << -1 << endl;
                break;
            }
            else if (n == 1)
            {
                cout << y << endl;
                break;
            }
            else if (n % 6 == 0)
            {
                n = n / 6;
            }
            else
            {
                n = n * 2;
            }
            y++;
        }
    // }
    // else
    // {
    //     cout << -1 << endl;
    // }
}
return 0;
}