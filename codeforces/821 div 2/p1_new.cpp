#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        vector<vector<long long>> vn(k);
        for (auto &val : v)
        {
            cin >> val;
        }
        int a = k;
        for (long long i = 0; i < n; i++)
        {
            if (a == 0)
            {
                break;
            }
            for (long long j = i + 1; j < n; j++)
            {
                if (a == 0)
                {
                    break;
                }
                if ((i % k != j % k) || (v[i] >= v[j]))
                {
                    continue;
                }
                else
                {
                    long long temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                    a--;
                }
            }
        }
        for (auto &val : v)
        {
            // cout << val << " ";
        }
        // cout << endl;
        long long s = 0;
        for (long long i = 0; i < n - k + 1; i++)
        {
            long long h = 0;
            for (long long j = i; j < i + k; j++)
            {
                h += v[j];
            }
            s = max(s, h);
        }
        cout << s << endl;
    }
    return 0;
}