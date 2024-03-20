#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL x, y, n;
    cin >> x >> y >> n;
    vector<LL> a(n);
    a[n - 1] = y;
    int fct = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        a[i] = a[i + 1] - fct;
        fct++;
    }
    // for (auto &val : a)
    //     cout << val << " ";
    // cout << endl;
    if (a[0] >= x)
    {
        a[0] = x;
        for (auto &val : a)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    else
        cout << "-1" << endl;
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