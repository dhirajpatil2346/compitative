#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 0 && a > b)
    {
        cout << 1 << endl;
    }
    else
    {
        int j = c;
        int diff = a - b;
        c -= diff;
        b += diff;
        if (c < 0)
        {
            cout << j + 1 << endl;
        }
        else if (c + a <= b)
        {
            cout << 0 << endl;
        }
        else if (c % 2 == 0)
        {
            diff += c / 2;
            cout << c + diff << endl;
        }
        else
        {
            cout << c + diff + c / 2 + 1 << endl;
        }
    }
    return 0;
}