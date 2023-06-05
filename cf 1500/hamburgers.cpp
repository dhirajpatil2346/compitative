#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string s;
    cin >> s;
    vector<long long> curr(3), price(3);
    for (auto &val : curr)
        cin >> val;
    for (auto &val : price)
        cin >> val;
    LL extra;
    cin >> extra;
    map<char, LL> m;
    m['B'] = 0, m['S'] = 0, m['C'] = 0;
    for (auto &val : s)
        m[val]++;
    LL ans = 0;
    vector<long long> req(3);
    req[0] = m['B'], req[1] = m['S'], req[2] = m['C'];
    LL tr = 0;
    for (int i = 0; i < 3; i++)
        tr += req[i] * price[i];
    LL l = 0, r = 1e13;
    while (l <= r)
    {
        LL mid = (l + r) / 2;
        LL need = 0;
        for (int i = 0; i < 3; i++)
        {
            if (req[i] == 0)
                continue;
            LL real_need = req[i] * mid - curr[i];
            if (real_need <= 0)
                continue;
            need += price[i] * real_need;
        }
        if (need <= extra)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
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