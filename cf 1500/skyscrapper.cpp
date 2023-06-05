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
    for (int i = 1; i < n - 1; i++)
    {
        if ((v[i - 1] > v[i]) && (v[i] < v[i + 1]))
        {
            if (v[i - 1] <= v[i + 1])
                v[i - 1] = v[i];
            else
                v[i + 1] = v[i];
        }
    }
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}