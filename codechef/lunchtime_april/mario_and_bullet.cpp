#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int te = y / x;
        if (te < z)
        {
            cout << z - te << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}