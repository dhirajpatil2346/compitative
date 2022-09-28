#include <bits/stdc++.h>
using namespace std;

int main()
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
        sort(v.begin(), v.end());
        if (v[n - 1] >= 0)
        {
            cout << min(v[0] * v[0], v[0] * v[n - 1]) << " " << max(v[0] * v[0], v[n - 1] * v[n - 1]) << endl;
        }
        else
        {
            cout << v[n - 1] * v[n - 1] << " " << v[0] * v[0] << endl;
        }
    }
    return 0;
}