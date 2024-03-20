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
    sort(v.begin(), v.end());
    LL c = 0, ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        v[i] -= c;
        ans = max(ans, v[i]);
        // cout << c << endl;
        c += v[i];
        // cout << c << " " << v[i] << endl;
    }
    v.back() = ans;
    cout << v.back() << endl;
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