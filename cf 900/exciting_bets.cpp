#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        long long gcd = abs(n - m);
        long long got = false;
        long long i = 0;
        if (gcd == 0)
        {
            got = true;
        }
        else if (n % gcd == 0 && m % gcd == 0)
        {
            got = true;
        }
        while (!got)
        {
            i++;
            n++, m++;
            if (n % gcd == 0 && m % gcd == 0)
            {
                got = true;
            }
        }
        cout << gcd << " " << i << endl;
    }
    return 0;
}