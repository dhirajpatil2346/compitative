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
        if (n % 3 == 0)
        {
            cout << n / 3 << " " << n / 3 + 1 << " " << n / 3 - 1 << endl;
        }
        else if (n % 3 == 1)
        {
            int a = n / 3, b = n / 3, c = n / 3;
            b += 2;
            c--;
            cout << a << " " << b << " " << c << endl;
        }
        else
        {
            int a = n / 3, b = n / 3, c = n / 3;
            c--;
            b += 2;
            a++;
            cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}