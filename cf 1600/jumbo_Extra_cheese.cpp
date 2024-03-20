#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    LL sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        LL a, b;
        cin >> a >> b;
        sum += 2ll * min(a, b);
        mx = max(mx, max(a, b));
    }
    sum += 2 * mx;
    cout << sum << endl;
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