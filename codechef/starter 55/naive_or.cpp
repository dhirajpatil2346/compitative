#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long p, q, r;
        cin >> p >> q >> r;
        long long z = 0;
        for (long long i = 0; i <= r; i++)
        {
            for (long long j = 0; j <= r; j++)
            {
                for (long long k = 0; k <= r; k++)
                {
                    if (((i | j) == p) && ((j | k) == q) && ((k | i) == r))
                    {
                        // cout << i << " " << j << " " << k << endl;
                        z++;
                    }
                }
            }
        }
        cout << z << endl;
    }
    return 0;
}