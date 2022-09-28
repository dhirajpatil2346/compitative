#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        long long ans = 0;
        if (a - x >= n && b - x >= n && a <= b)
        {
            cout<<1<<endl;
            a -= n;
        }
        else if (a - x >= n && b - x >= n && b <= a)
        {
            cout<<2<<endl;
            b -= n;
        }
        else if(a-x >= n)
        {
            cout<<3<<endl;
            a-=n;
        }
        else if(b-y >= n)
        {
            cout<<4<<endl;
            b-=n;
        }
        else if (b - x >= n)
        {
            b -= n;
        }
        else
        {
            while (n--)
            {
                if (a >= b && (a > x && b > y))
                {
                    b--;
                }
                else if (b >= a && (a > x && b > y))
                {
                    a--;
                }
                else if (a == x && b > y)
                {
                    b--;
                }
                else if (b == y && a > x)
                {
                    a--;
                }
                cout << a << "  " << x << " " << b << " " << y << endl;
            }
        }
        ans = 1ll * a * b;
        cout << ans << endl;
    }
    return 0;
}