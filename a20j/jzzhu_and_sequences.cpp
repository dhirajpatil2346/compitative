#include <bits/stdc++.h>
using namespace std;
const long long m = 1e9 + 7;
signed main()
{
    /*
    a, b, c
    b = a + c
    c = b - a
    f[i] = f[i-1] - f[i-2]
    */
    // cout << m << endl;
    long long a, b, n;
    cin >> a >> b >> n;
    int c = b - a;
    if (n == 1)
    {
        c = a;
        if (c < 0)
        {
            cout << m + c;
        }
        else
        {
            cout << c << endl;
        }
    }
    else if (n == 2)
    {
        c = b;
        if (c < 0)
        {
            cout << m + c;
        }
        else
        {
            cout << c << endl;
        }
        // cout << b << endl;
    }
    else if (n == 3)
    {
        if (c < 0)
        {
            cout << m + c;
        }
        else
        {
            cout << c << endl;
        }
    }
    else
    {
        a = b;
        b = c;
        for (long long i = 4; i <= n; i++)
        {
            c = b - a;
            a = b;
            b = c;
        }
        if (c < 0)
        {
            cout << m + c;
        }
        else
        {
            cout << c << endl;
        }
    }
    return 0;
}