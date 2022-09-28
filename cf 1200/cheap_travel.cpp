#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n >= m)
    {
        if (b <= a)
        {
            // cout << "1st" << endl;
            if (n % m)
            {
                cout << min((n / m) * b + b, (n / m) * b + a);
            }
            else
            {
                cout << min(n * a, n * b / m) << endl;
            }
        }
        else
        {
            if (n % m)
            {
                cout << min((n / m) * b + (n % m) * b, (n / m) * b + (n % m) * a) << endl;
            }
            else
            {
                cout << min(n * a, n * b / m) << endl;
            }
        }
    }
    else
    {
        if (b <= a)
        {
            cout << b << endl;
        }
        else
        {
            cout << min(b, n * a) << endl;
        }
    }
    return 0;
}