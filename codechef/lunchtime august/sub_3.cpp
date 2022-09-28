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
        for (long long i = 0; i < n - 1; i++)
        {
            while (v[i + 1] > 1)
            {
                v[i + 1] -= 2;
                v[i]--;
            }
            if (v[i + 1] > 0 && v[i] > 0)
            {
                v[i + 1] -= 2;
                v[i]--;
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