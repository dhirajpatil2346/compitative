#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int f(int r, int c, vector<vector<int>> &v)
{
    if (r < 0 || c < 0)
        return 0;
    if (v[r][c] != 0)
        return v[r][c];
    return v[r][c] = f(r - 1, c, v) + f(r, c - 1, v);
}

void solve()
{
    LL x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << (x2 - x1) * (y2 - y1) + 1 << endl;
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