#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<LL> v(n), left(n), right(n);
    for (auto &val : v)
        cin >> val;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
            left[i] = v[i - 1] - v[i];
        left[i] += left[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] < v[i + 1])
            right[i] = v[i + 1] - v[i];
        right[i] += right[i + 1];
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a < b)
        {
            cout << left[b] - left[a] << endl;
        }
        else
        {
            cout << right[b] - right[a] << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}