#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    LL less = 0, more = 0;
    bool g = false;
    for (auto &val : v)
        if (val == k)
            g = true;
    for (auto &val : v)
        if (val <= k)
            less += abs(k - val);
        else
            more += abs(k - val);
    if (less == 0 && more == 0)
        cout << 0 << endl;
    else if ((less == more) || g)
        cout << 1 << endl;
    else
        cout << 2 << endl;
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