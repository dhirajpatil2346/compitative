#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<int> sum = v;
    for (int i = 1; i < n; i++)
        sum[i] += sum[i - 1];
    if (z == 0)
    {
        cout << sum[k] << endl;
        return;
    }
    k--;
    int ans = 0;
    for (int i = 1; i < n; i++, k--)
    {
        int csum = sum[i];
        if (k == 0)
        {
            ans = max(ans, csum);
            break;
        }
        // cout << endl;
        // cout << i << " " << csum << " " << k << " " << z << endl;
        int maxleft = k / 2 + k % 2;
        maxleft = min(maxleft, z);
        int mxc = maxleft - 1;
        csum += (mxc * v[i]);
        csum += (maxleft * v[i - 1]);
        int K = k;
        K -= maxleft;
        K -= mxc;
        csum += (sum[i - 1 + K] - sum[i - 1]);
        ans = max(ans, csum);
        // cout << i << " " << csum << endl;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}