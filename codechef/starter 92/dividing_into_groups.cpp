#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k, s = 0;
    cin >> n >> k;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<LL> till(n);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if ((i + k) > n)
            break;
        if ((i - 1) >= 0)
            till[i] += till[i - 1];
        v[i] += till[i];
        s += v[i];
        till[i] -= v[i];
        if ((i + k) < n)
            till[i + k] += v[i];
    }
    cout << s << endl;
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