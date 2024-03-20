#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    if (n % 2 == 0)
    {
        // if n is even then we can just decrease it
        int x = a[0];
        for (int i = 1; i < n; i++)
            x ^= a[i];
        int xo = b[0];
        for (int i = 1; i < m; i++)
            xo |= b[i];
        for (auto &val : a)
            val |= xo;
        int j = a[0];
        for (int i = 1; i < n; i++)
            j ^= a[i];
        cout << j << " " << x << endl;
    }
    else
    {
        // here n is odd
        // we can't decrase it
        // improve we can do
        int x = a[0];
        for (int i = 1; i < n; i++)
            x ^= a[i];
        int xo = b[0];
        for (int i = 1; i < m; i++)
            xo |= b[i];
        for (auto &val : a)
            val |= xo;
        int j = a[0];
        for (int i = 1; i < n; i++)
            j ^= a[i];
        cout << (x) << " " << j << endl;
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