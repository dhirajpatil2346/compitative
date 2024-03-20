#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n), left(n), right(n);
    for (auto &val : v)
        cin >> val;
    left[0] = INT_MAX, right[n - 1] = INT_MAX;
    LL mini = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        mini = min(v[i - 1], mini);
        left[i] = mini;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        mini = min(v[i + 1], mini);
        right[i] = mini;
    }
    // for (auto &val : left)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : right)
    //     cout << val << " ";
    // cout << endl;
    bool g = false;
    for (int i = 0; i < n; i++)
    {
        if ((v[i] > (left[i] + right[i])))
        {
            // cout << i << endl;
            g = true;
        }
    }
    if (g)
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
        solve();
    }
    return 0;
}