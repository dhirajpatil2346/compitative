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
        long long even = n / 2 + n % 2;
        long long odd = n / 2;
        long long f = 2 * even * odd;
        cout << f << endl;
    }
    return 0;
}