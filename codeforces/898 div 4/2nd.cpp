#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    int s = v[0];
    for (int i = 0; i < n; i++)
        s *= v[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int c = v[i] + 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            c *= v[j];
        }
        ans = max(ans, c);
    }
    cout << ans << endl;
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