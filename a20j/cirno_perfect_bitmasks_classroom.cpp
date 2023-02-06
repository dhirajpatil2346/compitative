#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1 || n==2)
        {
            cout << 3 << endl;
        }
        else if (((n) & (n - 1)) == 0)
        {
            cout << (n | 1) << endl;
        }
        else if (n & 1)
        {
            cout << 1 << endl;
        }
        else
        {
            ll ans = 0;
            for (int i = 0; i < 64; i++)
            {
                ll k = (1 << i);
                if (n & k)
                {
                    ans |= k;
                    break;
                }
            }
            cout << ans << endl;
        }
        /*
        0001 - 11
        0010 - 11
        0101 - 01
        1001 - 1
        10000 -
        */
    }
    return 0;
}