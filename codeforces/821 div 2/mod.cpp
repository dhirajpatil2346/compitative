#include <bits/stdc++.h>
using namespace std;

signed main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n + 1);
        vector<long long> mod(k);
        for (long long i = 1; i < n + 1; i++)
        {
            cin >> v[i];
            mod[i % k] = max(mod[i % k], v[i]);
        }
        long long ac = accumulate(mod.begin(), mod.end(), 0);
        cout << ac << endl;
    }
    return 0;
}