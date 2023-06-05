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
    set<int> dep;
    for (int i = 0; i < n; i++)
        if (v[i] == 0)
            dep.insert(i);
    vector<int> ans;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (auto &val : v)
        if (s.find(val) != s.end())
            s.erase(s.find(val));
    for (auto &val : v)
    {
        if (val != 0)
        {
            ans.push_back(val);
        }
        else
        {
            if (s.size())
            {
                ans.push_back(*(s.rbegin()));
                s.erase(prev(s.end()));
            }
        }
    }
    vector<int> fault;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == i + 1)
            fault.push_back(i);
    }
    for (auto &val : fault)
        if (dep.find(val) != dep.end())
            dep.erase(dep.find(val));
    for (int i = 0; i < (fault.size() - 1) && fault.size() > 1; i++)
    {
        auto temp = ans[fault[i]];
        ans[fault[i]] = ans[fault[i + 1]];
        ans[fault[i + 1]] = temp;
    }
    if (fault.size() == 1)
    {
        auto temp = ans[fault[0]];
        ans[fault[0]] = ans[*dep.begin()];
        ans[*dep.begin()] = temp;
    }
    for (auto &val : ans)
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