#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int maxi = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxi = max(maxi, v[i ] - v[i+1]);
        }
        // cout<<maxi<<endl;
        int max2 = 0;
        for (int i = 1; i < n; i++)
        {
            max2 = max(v[i], max2);
        }
        max2 -= v[0];
        int mini3 = v[0];
        for (int i = 0; i < n - 1; i++)
        {
            mini3 = min(mini3, v[i]);
        }
        int max3 = v[n - 1] - mini3;
        cout << max(maxi, max(max2, max3)) << endl;
    }
    return 0;
}