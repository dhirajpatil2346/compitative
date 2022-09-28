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
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x - 1] = y;
            int maxi = INT_MIN;
            int k = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (v[i] <= v[i + 1])
                {
                    continue;
                }
                else
                {
                    // cout << v[i] << "  " << v[i + 1] << endl;
                    while (v[i] > v[i + 1])
                    {
                        v[i + 1] += (i + 1);
                        k++;
                    }
                    maxi = max(maxi, k);
                    k = 0;
                }
            }
            cout << max(0, maxi) << endl;
        }
    }
    return 0;
}