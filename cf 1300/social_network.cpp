#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long k1 = 1ll;
        vector<long long> v;
        long long N = n;
        while (N--)
        {
            long long x;
            cin >> x;
            v.push_back(x);
            k1 *= x;
        }
        bool got = false;
        for (int i = 0; i < n; i++)
        {
            // cout << k1 / v[i] << endl;
            if ((k1 / v[i]) % k == 0)
                got = true;
        }
        if (got)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
