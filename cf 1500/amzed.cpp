#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(v[i]) == m.end())
            m[v[i]].push_back(-1);
        m[v[i]].push_back(i);
    }
    for (auto &val : m)
        val.second.push_back(n);
    vector<int> ans(n, -1);
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
    }
    return 0;
}