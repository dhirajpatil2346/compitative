#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> m;
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i] - i]++;
        }
        long long c = 0;
        for (auto &val : m)
        {
            int k = val.second;
            c += ((k - 1) *1ll *  (k)) / 2;
        }
        cout << c << endl;
    }
    return 0;
}