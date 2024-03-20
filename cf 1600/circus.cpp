#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    k %= 4;
    if (k == 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (k == 1 || k == 3)
        for (int i = 1; i <= n; i += 2)
            cout << i << " " << i + 1 << endl;
    else if (k == 2)
    {
        for (int i = 3, j = 4; i <= n; i += 4, j += 4)
            cout << i << " " << j << endl;
        for (int i = 2, j = 1; i <= n; i += 4, j += 4)
            cout << i << " " << j << endl;
    }
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