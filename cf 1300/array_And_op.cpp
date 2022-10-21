#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        sort(v.rbegin(), v.rend());
        vector<int> final(2 * k);
        for (int i = 0; i < 2 * k; i++)
        {
            final[i] = v[i];
        }
        int i = 0, j = k;
        long long sc = 0;
        while ( j < 2 * k)
        {
            sc += min(final[i] / final[j], final[j] / final[i]);
            final[i] = 0, final[j] = 0;
            i++;
            j++;
        }
        long long z = 0;
        for (int i = 2 * k; i < n; i++)
        {
            z += v[i];
        }

        cout << z + sc << endl;
    }
    return 0;
}