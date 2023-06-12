#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    int pos = n - 1;
    while (pos >= 0 && v[pos] == pos + 1)
        pos--;

    long double l = 1.0, one = 1.0;
    while (m--)
    {
        int p;
        long double cp;
        cin >>
            p >> cp;
        if (p >= pos + 1)
        {
            // cout << p << " " << cp << endl;
            long double j = (long double)(one * one - cp * one);
            // cout << "--> " << l << " " << j << endl;
            l *= j;
            // cout << l << endl;
        }
    }
    if (pos == -1)
    {
        cout << 1 << endl;
        return;
    }
    cout << one - l << endl;
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