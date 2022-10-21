#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int k = min(m, n - m);
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < k; i++)
        {
            sum1 += v[i];
        }
        for (int i = k; i < n; i++)
        {
            sum2 += v[i];
        }
        cout << sum2 - sum1 << endl;
    }
    return 0;
}