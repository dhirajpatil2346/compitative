#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v1(n), v2(n);
        for (auto &val : v1)
        {
            cin >> val;
        }
        for (auto &val : v2)
        {
            cin >> val;
        }
        int m1 = *max_element(v1.begin(), v1.end());
        int m2 = *max_element(v2.begin(), v2.end());
        if (m1 >= m2)
        {
            long double z = accumulate(v1.begin(), v1.end(), 0ll);
            long double o = n;
            cout << z / o << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v2[i] == m2)
                {
                    cout << v1[i] << endl;
                    break;
                }
            }
        }
    }
    return 0;
}