#include <bits/stdc++.h>
using namespace std;
#define LL long long
void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    LL t;
    cin >> t;
    LL maxi = *max_element(v.begin(), v.end());
    for (LL i = maxi; i <= 1e3; i++)
    {
        LL z = 0;
        LL j = 0;
        while (j < n)
        {
            LL sum = 0;
            while (j < n && sum + v[j] <= i)
            {
                sum += v[j];
                j++;
            }
            // cout << j << " " << sum << endl;
            z++;
        }
        if (z <= t)
        {
            cout << i << endl;
            return;
        }
    }
    // cout << n << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}