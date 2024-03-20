#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL solve()
{
    LL l, r, a;
    cin >> l >> r >> a;
    if (l == r)
        return l / a + l % a;
    LL f = (r / a + 1) * a - 1;
    if (f > r)
        f -= a;
    if (f >= l && f <= r)
        return f / a + f % a;
    f = l;
    LL ans = INT_MIN;
    for (LL i = f; i <= r; i++)
        ans = max(ans, i / a + i % a);
    return ans;
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
        cout << solve() << endl;
    }
    return 0;
}