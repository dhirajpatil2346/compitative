#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0, d = 0;
    while (n--)
    {
        int i, j;
        cin >> i >> j;
        if (i == 0)
        {
            a++;
        }
        else
        {
            b++;
        }
        if (j == 0)
        {
            c++;
        }
        else
        {
            d++;
        }
    }
    // cout << a << " " << b << " " << c << " " << d << endl;
    int m1, m2;
    if (a < b)
    {
        m1 = a;
    }
    else
    {
        m1 = b;
    }
    if (c < d)
    {
        m2 = c;
    }
    else
    {
        m2 = d;
    }
    int req = m1 + m2;
    cout << req;
    return 0;
}