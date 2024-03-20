#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    LL ans = 0;
    for (LL i = 0, j = n - 1; i < n; i++, j--)
    {
        LL cans = 0;
        int J = j;
        if (i == 0)
            J = j - 1;
        for (LL k = J; k >= 0; k--)
        {
            LL p = pow(10, k);
            p %= mod;
            LL d = s[i] - '0';
            cans = (d * p) % mod;
            ans = (ans + cans) % mod;
        }
        cout << i << " " << ans << endl;
    }
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