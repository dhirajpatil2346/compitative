#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, h;
    cin >> n >> h;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // v.push_back(1e11);
    LL l = 1, r = 1e18, a = -1;
    while (l <= r)
    {
        LL m = (l + r) / 2;
        LL c = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
                c += m;
            else
                c += min(m, v[i + 1] - v[i]);
            if (c >= h)
                break;
        }
        // cout << m << " " << c << endl;
        if (c >= h)
        {
            r = m - 1;
            a = m;
        }
        else
            l = m + 1;
    }
    cout << a << endl;
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