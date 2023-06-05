#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    LL mn = 1e9;
    LL mx = 0;
    for (auto &val : v)
    {
        cin >> val;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == -1)
            continue;
        if ((i > 0 && v[i - 1] == -1) || (i < n - 1 && v[i + 1] == -1))
        {
            mn = min(mn, v[i]), mx = max(mx, v[i]);
        }
    }
    LL value = (mn + mx) / 2;
    vector<LL> test = {value - 1, value, value + 1};
    LL fans = INT_MAX, fval = -1;
    for (auto &val : test)
    {
        if (val < 0 || val > 1e9)
            continue;
        vector<LL> vn = v;
        for (auto &valu : vn)
            if (valu == -1)
                valu = val;
        LL mx = INT_MIN;
        for (int i = 0; i < n - 1; i++)
            mx = max(mx, abs(vn[i] - vn[i + 1]));
        if (mx < fans)
        {
            fans = mx;
            fval = val;
        }
    }
    cout << fans << " " << fval << endl;
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