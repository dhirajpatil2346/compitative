#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ld = long double;
#define endl "\n"
void solve()
{
    int n;
    ld l;
    cin >> n >> l;
    ld time = 0;
    ld p1 = 0, p2 = l, ans = 0.0;
    vector<ld> v(n);
    ld one = 1.0;
    for (auto &val : v)
        cin >> val;
    int i1 = -1, i2 = n;
    ld s1 = 1.0, s2 = 1.0;
    for (int _ = 0; _ < n; _++)
    {
        // cout << p1 << " " << p2 << " " << ans << endl;
        ld d1 = v[i1 + 1] - p1, d2 = p2 - v[i2 - 1];
        // cout << d1 << " " << s1 << " " << d2 << " " << s2 << endl;
        ld t1 = d1 / s1, t2 = d2 / s2;
        // cout << t1 << " " << t2 << endl;
        if (t1 <= t2)
        {
            ans = t1 + ans;
            p1 = p1 + s1 * t1, p2 = p2 - s2 * t1;
            i1++;
            s1 = s1 + one;
        }
        else
        {
            ans = ans + t2;
            p1 = p1 + s1 * t2, p2 = p2 - s2 * t2;
            i2--;
            s2 = s2 + one;
        }
    }
    // final
    ans += (p2 - p1) / (s1 + s2);
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
/*
v = d/t
d = p2 - p1
v = s1 + s2
t  = d / t
ans += (p2-p1)/(s1+s2)
*/