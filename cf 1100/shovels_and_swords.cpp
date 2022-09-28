#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        while (a && b && (a > 1 || b > 1))
        {
            while ((a && b && (a > 1 || b > 1)) && a >= b)
            {
                a -= 2;
                b--;
                ans++;
            }
            while ((a && b && (a > 1 || b > 1)) && b >= a)
            {
                b -= 2;
                a--;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}