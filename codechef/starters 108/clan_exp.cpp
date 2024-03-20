#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x].push_back(i);
    }
    int sans = n, pt = m.begin()->first;
    for (auto &val : m)
    {
        int ans = 0;
        // cout << ans << endl;
        ans = max(ans, val.second.front());
        ans = max(ans, (n - 1) - (val.second.back()));
        // cout << ans << endl;
        for (int i = 1; i < val.second.size(); i++)
        {
            int diff = val.second[i] - val.second[i - 1] - 1;
            diff = diff / 2 + (diff % 2);
            ans = max(ans, diff);
        }
        // cout << val.first << " " << ans << endl;
        if (sans > ans)
        {
            sans = ans;
            pt = val.first;
        }
    }
    cout << pt << " " << sans << endl;
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