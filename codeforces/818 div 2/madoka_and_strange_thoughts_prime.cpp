#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long c = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int j = min(3, n / i);
            // cout << i << " " << j << endl;
            c += 2 * j - 1;
        }
        cout << c << endl;
    }
    return 0;
}