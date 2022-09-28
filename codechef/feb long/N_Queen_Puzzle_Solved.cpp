#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long double n;
        cin >> n;
        long double y = pow(0.143 * n, n);
        // cout<<y;
        long double diff = y - int(y);
        // cout<<diff;
        if (diff < 0.5)
        {
            cout << int(y) << endl;
        }
        else
        {
            cout << int(y) + 1 << endl;
        }
    }
    return 0;
}