#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> ind;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
            ind.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i + k ) > n)
            break;
        auto it = lower_bound(ind.begin(), ind.end(), i);
        if (it == ind.end())
            break;
        int diff = *it - i;
        if (diff < k)
            ans++;
        // cout << i << " " << ans << endl;
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