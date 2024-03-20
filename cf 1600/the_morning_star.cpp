#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    map<LL, LL> diff, x, y;
    vector<pair<LL, LL>> vp[4];
    LL z = 0, eq = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            z++, x[a]++, y[b]++;
            continue;
        }
        if (a > 0 && b > 0)
            vp[0].push_back({a, b});
        else if (a < 0 && b < 0)
            vp[2].push_back({a, b});
        else if (b < 0)
            vp[1].push_back({a, b});
        else if (a < 0)
            vp[3].push_back({a, b});
        if (abs(a) == abs(b))
            eq++;
    }
    LL ans = 2ll * z * eq;
    cout << ans << endl
         << endl;
    for (auto &val : diff)
        cout << val.first << " " << val.second << endl;
    cout << endl;
    for (auto &val : x)
        cout << val.first << " " << val.second << endl;
    cout << endl;
    for (auto &val : y)
        cout << val.first << " " << val.second << endl;
    cout << endl;
    for (auto &val : diff)
        ans += (val.second * (val.second - 1));
    for (auto &val : x)
        ans += (val.second * (val.second - 1));
    for (auto &val : y)
        ans += (val.second * (val.second - 1));
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