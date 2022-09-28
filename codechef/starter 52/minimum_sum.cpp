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
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        bool one = false;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int gc = __gcd(v[i], v[j]);
                if (gc == 1)
                {
                    one = true;
                    break;
                }
            }
        }
        if (one)
        {
            cout << n << endl;
        }
        else
        {
            vector<bool> vis(n);
            for (long long i = 0; i < n; i++)
            {
                if (vis[i])
                {
                    continue;
                }
                for (long long j = i + 1; j < n; j++)
                {
                    if (vis[j])
                    {
                        continue;
                    }
                    if (v[j] % v[i] == 0)
                    {
                        v[j] = v[i];
                        vis[j] = true;
                    }
                }
            }
            long long sum = accumulate(v.begin(), v.end(), 0);
            cout << sum << endl;
        }
    }
    return 0;
}