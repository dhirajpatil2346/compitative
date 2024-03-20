#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int l, r, m;
    cin >> l >> r >> m;
    int a = (l / m) + (l % m), b = (r / m) + (r % m), c = 0;
    int f = r / m;
    f *= m;
    f--;
    if (f >= l && f <= r)
        c = (f / m) + (f % m);
    cout << max(a, max(b, c)) << endl;
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