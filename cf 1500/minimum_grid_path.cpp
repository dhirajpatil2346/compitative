#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    LL ans = 1e18;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<LL> pre = v;
    for (int i = 2; i < n; i++)
        pre[i] += pre[i - 2];
    vector<LL> track = pre;
    for (LL i = 0, e0 = 0, e1 = 0, me = 1e16, mo = 1e16; i < n; i++)
    {
        e0 += (i % 2 == 0);
        e1 += (i % 2 == 1);
        if (i & 1)
            mo = min(mo, v[i]);
        else
            me = min(me, v[i]);
        if (i & 1)
            track[i] += (mo * (n - e1));
        else
            track[i] += (me * (n - e0));
    }
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, track[i] + track[i - 1]);
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