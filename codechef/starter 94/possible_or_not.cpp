#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    LL k;
    cin >> k;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    set<LL> s;
    for (auto &val : v)
        if ((val & k) == k)
            s.insert(val);

    if (s.size() == 0)
    {
        cout << "NO" << endl;
        return;
    }
    LL f = *s.begin();
    for (auto &val : s)
        f &= val;
    // cout << f << endl;
    if (f == k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
        // cout << (3 & 4) << endl;
        solve();
    }
    return 0;
}