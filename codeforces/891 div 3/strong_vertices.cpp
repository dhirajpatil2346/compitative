#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    // cout << n << endl;
    vector<int> v1(n), v2(n);
    for (auto &val : v1)
        cin >> val;
    for (auto &val : v2)
        cin >> val;
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++)
        m[v1[i - 1] - v2[i - 1]].push_back(i);
    auto f = *m.rbegin();
    cout << f.second.size() << endl;
    for (auto &val : f.second)
        cout << val << " ";
    cout << endl;
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