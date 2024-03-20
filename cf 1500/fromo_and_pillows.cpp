#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, m, k;
    cin >> n >> m >> k;
    LL l = 1, r = 1e9;
    LL ans = m / n + min(m % n, 1ll);
    while (l <= r)
    {
        // LL mid = (l + r) / 2ll;
        LL mid = 1001;
        LL sa = ((k) * (2ll * mid + (k - 1) * (-1ll))) / 2ll;
        LL ta = k + (k - 1) * (1ll), tb = (mid - 1) + (n - k - 1ll) * (-1ll);
        LL sb = ((n - k)) * (2ll * (mid - 1) + (n - k - 1ll) * (-1ll)) / 2ll;
        cout << mid << " " << sa << " " << sb << endl;
        sa += sb;
        if (ta <= 0 || tb <= 0 || sa > m)
        {
            r = mid - 1;
            // continue;
        }
        else
        {
            ans = max(mid, ans);
            l = mid + 1;
        }
        // LL sb = ((n - k)) * (2ll * (mid - 1) + (n - k - 1ll) * (-1ll)) / 2ll;
        // cout << mid << " " << sa << " " << sb << endl;
        // sa += sb;
        // if (sa <= m)
        // {
        //     ans = mid;
        //     l = mid + 1;
        // }
        // else
        //     r = mid - 1;
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
/*
1 2 3 2 1

*/