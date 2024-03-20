#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> left(n);
    vector<int> right(n);
    for (auto &val : left)
    {
        cin >> val;
        if (val == 2)
            val = -1;
    }
    for (auto &val : right)
    {
        cin >> val;
        if (val == 2)
            val = -1;
    }
    map<int, int> m;
    m[0] = 0;
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        c += left[i - 1];
        m[c] = i;
    }
    if ((accumulate(left.begin(), left.end(), 0) + accumulate(right.begin(), right.end(), 0)) == 0)
    {
        cout << 0 << endl;
        return;
    }
    int acc = accumulate(right.begin(), right.end(), 0);
    c = 0;
    int ans = 2 * n;
    for (auto &val : m)
        cout << val.first << " " << val.second << endl;
    for (int i = 0; i < n; i++)
    {
        int rightused = i + 1;
        c += right[i];
        int need = c * (-1);
        if (m.find(need) == m.end())
            continue;
        int leftused = n - m[need];
        ans = min(ans, leftused + rightused);
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