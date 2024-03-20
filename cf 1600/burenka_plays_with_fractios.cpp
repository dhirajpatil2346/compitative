#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    a *= d, b *= c;
    LL g = __gcd(a, b);
    LL ans = 0;
    ans += (g != a);
    ans += (g != b);
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