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
    vector<int> a1, a2;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    set<int> vis;
    for (int i = 0; i < n; i++)
    {
        if (vis.find(v[i]) == vis.end())
        {
            a1.push_back(v[i]);
            vis.insert(v[i]);
            s.erase(v[i]);
        }
        else
        {
            a1.push_back(*s.begin());
            s.erase(s.begin());
        }
    }
    vis.clear();
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 0; i < n; i++)
    {
        if (vis.find(v[i]) == vis.end())
        {
            a2.push_back(v[i]);
            vis.insert(v[i]);
            s.erase(v[i]);
        }
        else
        {
            auto it = prev(s.lower_bound(v[i]));
            a2.push_back(*it);
            s.erase(it);
        }
    }
    for (auto &val : a1)
        cout << val << " ";
    cout << endl;
    for (auto &val : a2)
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