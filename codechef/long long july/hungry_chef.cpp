#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, n, r;
        cin >> x >> y >> n >> r;
        int k = r / y;
        // cout<<n*x<<"  "<<r<<endl;
        if ((n * x) > r)
        {
            cout << -1 << endl;
        }
        else
        {
            while (true)
            {
                int p = k + (r - (k * y)) / x;
                if (p >= n)
                {
                    k = min(n, k);
                    cout << n - k << " " << k << endl;
                    break;
                }
                k--;
            }
        }
    }
    return 0;
}