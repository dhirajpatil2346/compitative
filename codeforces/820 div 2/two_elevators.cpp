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
        int da = abs(a - 1);
        int db = 0;
        if (b < c)
        {
            db = abs(b - c) + abs(c - 1);
        }
        else
        {
            db = abs(b - 1);
        }
        if (a == b && b == c && c == 1)
        {
            cout << 1 << endl;
        }
        else if (da == db)
        {
            cout << 3 << endl;
        }
        else if (da < db)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}