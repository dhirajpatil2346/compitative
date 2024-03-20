#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k, x;
    cin >> n >> k >> x;
    LL minsum = (k * (1ll + k)) / 2ll;
    LL maxsum = (k * (n + n - k + 1ll)) / 2ll;
    if (x < minsum || x > maxsum)
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
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