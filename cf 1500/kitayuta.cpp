#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<int> v(3e4 + 1);
map<pair<int, int>, int> m;
int f(int ind, int d)
{
    // cout << ind << " " << d << endl;
    if (ind >= 3e4 + 1)
        return 0;
    if (m.find({ind, d}) != m.end())
        return m[{ind, d}];
    int ret = v[ind];
    int mx = 0;
    mx = max(mx, f(ind + d, d));
    if ((d - 1) > 0)
        mx = max(mx, f(ind + d - 1, d - 1));
    mx = max(mx, f(ind + d + 1, d + 1));
    return m[{ind, d}] = ret;
}
void solve()
{
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[x]++;
    }
    cout << f(d, d) << endl;
    cout << m.size() << endl;
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