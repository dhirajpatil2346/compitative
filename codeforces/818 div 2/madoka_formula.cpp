#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long j = 0;
        long long z = 6 * (n / 6);
        j += z * 3 - z / 2;
        if (n % 6)
        {
            long long k = n % 6;
            k--;
            j += 1 + 2 * k;
        }
        cout << j << endl;
    }
    return 0;
}