#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int f =( (m + n) / 4);
        int min;
        if (f >= n)
        {
            min = n;
        }
        else
        {
            min = m;
        }
        if (f <= min)
        {
            cout << f << endl;
        }
        else
        {
            cout << min << endl;
        }
    }
    return 0;
}