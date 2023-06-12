#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL a, b, c;
    cin >> a >> b >> c;
    if (a < c)
        cout << 1 << " ";
    else
        cout << -1 << " ";
    if (b * a > c)
        cout << b << endl;
    else
        cout << -1 << endl;
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