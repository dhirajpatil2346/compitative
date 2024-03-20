#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    LL f = v[0];
    for (auto &val : v)
        f &= val;
    int groups = 1;
    LL c1 = v[0];
    int i = 1;
    vector<bool> vis(n, false);
    vis[0] = true;
    // if (c1 != f)
    for (; i < n; i++)
    {
        if (c1 == f)
            break;
        c1 &= v[i];
        vis[i] = true;
    }
    for (; i < n; i++)
    {
        if (vis[i])
            continue;
        LL c = v[i];
        vis[i] = true;
        for (int j = i + 1; j < n; j++)
        {
            if (c == 0)
                break;
            c &= v[j];
            vis[j] = true;
        }
        if (c == 0)
            groups++;
    }
    cout << groups << endl;
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
/*
21
325

*/
/*
1 3 5 7 => 1 3 5 7 1


*/