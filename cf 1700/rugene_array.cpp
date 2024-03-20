#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, ans = 0;
    cin >> n;
    map<LL, LL> m;
    m[0] = -1;
    // LL z = 0;
    LL curr = 0;
    LL l = 0;
    for (LL i = 0; i < n; i++)
    {
        LL x = 41;
        cin >> x;
        curr += x;
        // cout << i << " " << l << " " << curr << endl;
        if (x == 0)
        {
            m.clear();
            l = i + 1;
            curr = 0;
            m[0] = i;
        }
        else
        {
            if (m.find(curr) != m.end())
                l = max(l, m[curr] + 2ll);
            LL e = i - l + 1ll;
            if (e > 0)
                ans += e;
            m[curr] = i;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}