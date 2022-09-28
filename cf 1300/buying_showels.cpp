#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int m = sqrt(n);
        int z = min(m, k);
        int ans = n;
        // cout << z << endl;
        for (int i = z; i >= 1; i--)
        {
            if ((n % i == 0) && (n / i <= k) && (i <= k))
            {
                ans = min(ans, min(i, n / i));
            }
            else if ((n % i) == 0)
            {
                ans = min(ans, n / i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}