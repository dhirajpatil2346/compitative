#include <bits/stdc++.h>
using namespace std;

bool comapare(int a, int b, int k)
{
    int j = a % k;
    int z = b % k;
    return (j == z && a > b);
}

signed main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        vector<int> odd, even;
        for (auto &val : v)
        {
            cin >> val;
            if (val % 2)
            {
                odd.push_back(val);
            }
            else
            {
                even.push_back(val);
            }
        }
        sort(v.begin(), v.end(), compare);
        for (auto &val : v)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}