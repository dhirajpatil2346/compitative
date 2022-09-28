#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        for (long long i = 0; i < n - 1; i++)
        {
            long long init1 = abs(v[i]) + abs(v[i + 1]);
            long long next1 = abs(v[i] - 1) + abs(v[i + 1] - 2);
            if (init1 <= next1)
            {
                continue;
            }
            int step = (v[i+1] -1 )/2;
            v[i]-=step;
            v[i+1]-=(2*step);
            while (true)
            {
                // cout << i << "  " << v[i] << "   " << v[i + 1] << endl;
                long long init = abs(v[i]) + abs(v[i + 1]);
                long long next = abs(v[i] - 1) + abs(v[i + 1] - 2);
                if (init <= next)
                {
                    break;
                }
                else
                {
                    v[i]--;
                    v[i + 1] -= 2;
                }
            }
        }

        long long sum = 0;
        for (long long i = 0; i < n; i++)
        {
            sum += abs(v[i]);
        }
        cout << sum << endl;
    }
    return 0;
}