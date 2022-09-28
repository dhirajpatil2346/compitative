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
        vector<long long> v(n), v1(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        for (auto &val : v1)
        {
            cin >> val;
        }
        long long op1 = 0, op2 = 0;
        for (long long i = 0; i < n; i++)
        {
            long long j = i;
            if (v[i] == v1[j])
            {
                continue;
            }
            else if (v[i] < v1[j])
            {
                op1 += abs(v[i] - v1[j]);
            }
            else
            {
                op2 += abs(v[i] - v1[j]);
            }
        }

        // cout << op1 << "   " << op2 << endl;
        if (op1 == op2)
        {
            cout << op1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}