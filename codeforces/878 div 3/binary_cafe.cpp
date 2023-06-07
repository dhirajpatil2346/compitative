#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    k = min(40ll, k);
    LL mx = (1ll << k) - 1;
    cout << min(mx + 1, n + 1) << endl;
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