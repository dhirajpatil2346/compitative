#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int x = a, y = b;
        int bn = 0, an = 0;
        if (x == 0 || y == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            while (y && x % 3 != 0)
            {
                x = abs(x - y);
                an++;
            }
            x=a,y=b;
            while (x && y % 3 != 0)
            {
                y = abs(x - y);
                bn++;
                if(bn>an)
                {
                    break;
                }
            }
            cout << min(an, bn) << endl;
        }
    }
    return 0;
}