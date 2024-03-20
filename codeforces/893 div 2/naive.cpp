#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        int c = i;
        while (c <= n && !vis[c])
        {
            vis[c] = true;
            cout << c << " ";
            c *= 2;
        }
    }
    cout << endl;
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