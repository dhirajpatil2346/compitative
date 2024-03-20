#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool solve()
{
    int n;
    cin >> n;
    vector<int> a(n), ca(n), b(n), cb(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : ca)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    for (auto &val : cb)
        cin >> val;
    map<int, multiset<int>> ms;
    for (int i = 0; i < n; i++)
        ms[cb[i]].insert(b[i]);
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (ms.find(ca[i]) == ms.end())
            continue;
        vis[i] = true;
        ms[ca[i]].insert(a[i]);
    }
    vector<int> ans = {0};
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            ms[ca[i]].insert(a[i]);
        auto it = ms[ca[i]].lower_bound(ans.back());
        if (it == ms[ca[i]].end())
            return false;
        ms[ca[i]].erase(ms[ca[i]].find(*it));
        ans.push_back(*it);
    }
    return true;
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}