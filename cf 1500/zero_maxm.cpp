#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n), b(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            if (a[i] == 0)
                ans++;
            else
                m[{0, 0}]++;
        }
        else if (a[i] != 0)
        {
            if (b[i] < 0)
                a[i] *= (-1), b[i] *= (-1);
            int g = __gcd(abs(a[i]), abs(b[i]));
            a[i] /= g, b[i] /= g;
            m[{a[i], b[i]}]++;
        }
    }
    int mx = 0;
    for (auto &val : m)
        mx = max(mx, val.second);
    ans += mx;
    cout << ans << endl;
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