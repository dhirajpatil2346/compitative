#include <bits/stdc++.h>
using namespace std;
#define LL long long
using ld = long double;
#define endl "\n"
void solve()
{
    int n;
    ld d, h;
    ld one = 1.0, two = 2.0;
    cin >> n >> d >> h;
    vector<ld> v(n);
    for (auto &val : v)
        cin >> val;
    ld area = (ld)(d * h) / two;
    ld total = (h / 2) * (two * one + (h - one) * two); // total number of cubes
    ld single = area / total;
    ld ans = ((ld)(n)) * area;
    // cout << fixed << ans << endl;
    for (int i = 0; i < n - 1; i++)
    {
        ld diff = v[i + 1] - v[i];
        diff = min(h, diff);
        diff = abs(h - diff);
        ans -= ((diff / 2) * (two * single + (diff - one) * two * single));
    }
    cout << fixed << ans << endl;
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