#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b)
        {
            cout << a / c + a % c << endl;
        }
        else
        {
            int maxi = 0;
            if (b - a < c)
            {
                maxi = max((b % c), ((b - 1) % c));
                cout << maxi + a / c << endl;
            }
            else if (a == b && b == c)
            {
                cout << 1 << endl;
            }
            else if (b == c)
            {
                cout << c - 1 << endl;
            }
            else
            {
                cout << a / c + c - 1 << endl;
            }
        }
    }
    return 0;
}