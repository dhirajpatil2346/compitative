#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    set<LL> s;
    for (int i = 0; i < n; i++)
    {
        LL x;
        cin >> x;
        s.insert(x);
    }
    vector<LL> v(s.begin(), s.end());
    LL l = 0, r = v.size() - 1;
    LL p1 = (l + r) / 4;
    LL p2 = (2 * (l + r)) / 4;
    LL p3 = (3 * (l + r)) / 4;
    cout << p1 << " " << p2 << p3 << endl;
    p1 = v[p1], p2 = v[p2], p3 = v[p3];
    cout << p1 << " " << p2 << " " << p3 << endl;
    LL mx = 0;
    for (auto &val : v)
    {
        LL p = min(abs(p1 - val), min(abs(p2 - val), abs(p3 - val)));
        mx = max(mx, p);
    }
    cout << mx << endl;
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