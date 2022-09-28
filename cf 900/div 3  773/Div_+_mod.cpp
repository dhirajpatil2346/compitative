#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long maxi = INT_MIN;
        for (long long i = a; i <= b; i++)
        {
            maxi = max(maxi, i / c + i % c);
        }
        cout << maxi << endl;
    }
    return 0;
}