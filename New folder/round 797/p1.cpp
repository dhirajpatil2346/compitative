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
        int a = 0, b = 0, c = 0;
        if (n > 7)
        {
            if (n % 3 == 0)
            {
                a = n / 3 - 1;
                b = n / 3;
                c = n / 3 + 1;
            }
            else if (n % 3 == 2)
            {
                a = n / 3 + 1;
                b = n / 3 + 2;
                c = n / 3 - 1;
            }
            else
            {
                a = n / 3 + 1;
                b = n / 3 + 2;
                c = n / 3 - 2;
            }
            cout << a << " " << b << " " << c << endl;
        }
        else
        {
            if (n == 6)
            {
                cout << "2 3 1" << endl;
            }
            else if (n == 7)
            {
                cout << "2 4 1" << endl;
            }
        }
    }
    return 0;
}

/*
3x+3=n
x.. x+1.. x+2
(n-3)/3=x
*/