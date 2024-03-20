#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<LL> diff = {v[0]};
    for (int i = 1; i < n; i++)
        diff.push_back(v[i] - v[i - 1]);
    LL extra = 0;
    for (auto &val : diff)
        if (val > n)
        {
            if (extra == 0)
                extra = val;
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    map<LL, LL> m;
    for (auto &val : v)
        m[val]++;
    int cnt = 0;
    for (auto &val : m)
    {
        if (val.second > 1)
            cnt++;
    }
    if (cnt > 2)
    {
        cout << "NO" << endl;
        return;
    }
    for (auto &val : m)
    {
        if (val.second > 1)
            extra = val.first;
    }
    // set<LL> s;
    LL o = 0;
    for (int i = 1; i <= n; i++)
    {
        
    }
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