#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    cout << min(n, m) + 1 << endl;
    int x = 0, y = m;
    while (x <= n && y >= 0)
    {
        cout << x << " " << y << endl;
        x++, y--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}