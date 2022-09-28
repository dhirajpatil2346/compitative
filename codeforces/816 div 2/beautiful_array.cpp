#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, b, s;
        cin >> n >> k >> b >> s;
        long long z = (k - 1) * (n - 1) + k * b + k - 1;
        if (s > z || k * b > s)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<long long> v(n);
            long long total = s;
            long long j = 0; // for traversal
            long long first = min(s, k * b + (k - 1));
            v[0] = first;
            total -= first;
            j++;
            while (j < n && total)
            {
                long long mini = min(total, k - 1);
                v[j] = mini;
                j++;
                total -= mini;
            }
            while (j < n)
            {
                v[j] = 0;
                j++;
            }
            for (auto &val : v)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}