#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    LL l = 1, r = 1414213569ll;
    LL ans = r;
    while (l <= r)
    {
        LL m = (l + r) / 2ll;
        LL c = m * (m - 1ll);
        c /= 2ll;
        if (c >= n)
        {
            ans = m;
            r = m - 1ll;
        }
        else
            l = m + 1ll;
    }
    LL currval = (((ans) * (ans - 1ll))) / 2ll;
    // cout << ans << " " << currval << endl;
    LL currfact = ans - 1ll;
    if (currval > n)
    {
        ans--;
        currval -= currfact;
        currfact--;
    }
    cout << ans + abs(currval - n) << endl;
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