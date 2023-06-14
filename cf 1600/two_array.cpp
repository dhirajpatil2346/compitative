#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<LL> curr(n, 1);
    for (int _ = 0; _ < m; _++)
    {
        vector<LL> newcurr(n);
        for (int row = 0; row < n; row++)
        {
            for (LL i = row, num = 1; i < n; i++, num++)
            {
                newcurr[row] += num * curr[i];
                newcurr[row] %= mod;
            }
        }
        curr = newcurr;
    }
    cout << curr.front() << endl;
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