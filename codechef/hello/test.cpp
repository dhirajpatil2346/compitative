#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c, int d)
{
    double a1 = a, b1 = b, c1 = c, d1 = d;
    if (a == 0 && c == 0)
    {
        cout << 0 << endl;
    }
    else if (a == 0 || c == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        double f1 = a1 / b1, f2 = c1 / d1;
        double r1 = max(f1, f2), r2 = min(f1, f2);
        if (f1 == f2)
        {
            cout << 0 << endl;
        }
        else
        {
            double k = (b1 * c1) / (d1 * a1);
            double k1 = 1/k;
            // cout << k << endl;
            double r11 = max(k1,k);
            int z = int(r11);
            if (z == r11)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
    }
}

int main()
{
    
  freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        solve(a, b, c, d);
    }
    return 0;
}

/*

a/b = c/d
 k=(b*c)/(d*a)

*/