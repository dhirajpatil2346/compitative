#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    map<int, LL> m;
    LL ans = n;
    for (int i = 0; i < n; i++)
    {
        for (auto &val : m)
        {
            if (v[i] % (val.first + 1) == 0)
                ans = (ans + val.second) % mod;
        }
        map<int, LL> mp;
        for (auto &val : m)
        {
            if (v[i] % (val.first + 1) == 0)
                mp[val.first+1]++;
        }
        for (auto &val : mp)
            m[val.first] += val.second;
        m[1]++;
        cout << i << " -> ";
        for (auto &val : m)
            cout << val.first << " " << val.second << endl;
        cout << endl;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}