#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d;
    cin >> a >> b;
    if (a > 0 && b > 0)
    {
        // qudrant 1
        int x1, y1, x2, y2;
        int m = abs(a) + abs(b);
        cout << "0 " << m << " " << m << " 0\n";
    }
    else if (a > 0 && b < 0)
    {
        // quadrant 4
        int x1, y1, x2, y2;
        int m = abs(a) + abs(b);
        cout << 0 << " " << -m
        <<" "
             << m <<" 0 " << endl;
    }
    else if (a < 0 && b < 0)
    {
        // quadrant 3
        int x1, y1, x2, y2;
        int m = abs(a) + abs(b);
        cout << -m
             << " 0 " << 0 << " " << -m;
    }
    else
    {
        // quadrant 2
        int x1, y1, x2, y2;
        int m = abs(a) + abs(b);
        cout << -m << " 0 "
             << "0 " << m << "\n";
    }

    return 0;
}