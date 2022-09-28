#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        if (sy - d > 1 && sx + d < n || sx - d > 1 && sy + d < m)
        {
            cout << abs(n + m - 2) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}