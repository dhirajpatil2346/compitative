#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        n*=2;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<int> r1(n / 2), r2(n / 2);
        for (int i = 0; i < n / 2; i++)
        {
            r1[i] = v[i];
        }
        for (int i = n / 2, j = 0; i < n; i++, j++)
        {
            r2[j] = v[i];
        }
        bool got = false;
        for (int i = 0; i < n / 2; i++)
        {
            if (r2[i] - r1[i] < k)
            {
                got = true;
                break;
            }
        }
        if (got)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}