#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0)
        {
            if (a > b)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        if (a == b)
        {
            if (c % 2)
            {
                cout << c / 2 + 1 << endl;
            }
            else
            {
                cout << c / 2 << endl;
            }
        }
        else if (a < b)
        {
            int diff = b - a;
            c -= diff;
            a += diff;
            if (c <= 0)
            {
                cout << 0 << endl;
            }
            else
            {
                if (c % 2 == 0)
                {
                    cout << c / 2 << endl;
                }
                else
                {
                    cout << c / 2 + 1 << endl;
                }
            }
        }
        else
        {
            if (c % 2)
            {
                cout << c / 2 + 1 << endl;
            }
            else
            {
                cout << c / 2 << endl;
            }
        }
    }
    return 0;
}