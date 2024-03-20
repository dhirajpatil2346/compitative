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
    vector<int> v1(n);
    v1[0] = -1;
    set<int> vis;
    vis.insert(v.back());
    for (int i = n - 2; i >= 0; i--)
        if (vis.find(v[i]) == vis.end())
            vis.insert(v[i]), v1[i + 1] = v[i];
        else
            v1[i + 1] = -1;
    set<int> to_add;
    for (int i = 0; i <= n + 5; i++)
        if (vis.find(i) == vis.end())
            to_add.insert(i);
    for (int i = 0; i < n; i++)
        if (v1[i] == -1)
        {
            v1[i] = *to_add.begin();
            to_add.erase(to_add.begin());
        }
    bool fault = false;
    set<int> curr;
    for (int i = 0; i <= n + 10; i++)
        curr.insert(i);
    for (int i = 0; i < n; i++)
    {
        curr.erase(v1[i]);
        if (*curr.begin() != v[i])
            fault = true;
    }
    if (fault)
    {
        cout << -1 << endl;
        return;
    }
    for (auto &val : v1)
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