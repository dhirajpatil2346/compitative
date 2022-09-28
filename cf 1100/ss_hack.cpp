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
        if (b > a)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        if (a >= 2 * b)
        {
            cout << b << endl;
        }
        else
        {
            cout << (a + b) / 3 << endl;
        }
    }
    return 0;
}