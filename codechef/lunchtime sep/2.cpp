#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x;
        cin >> a >> b >> x;
        int z = abs(a - b);
        if (z % 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            z /= 2;
            // cout << z << endl;
            if (z % x == 0 || z == x)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}