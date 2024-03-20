#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
using ld = long double;
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    map<LL, LL> m;
    for (auto &val : v)
        m[val]++;
    v.clear();
    for (auto &val : m)
        v.push_back(val.first);
    int q;
    cin >> q;
    while (q--)
    {
        LL ans = 0;
        LL x, y;
        cin >> x >> y;
        LL l = 0, r = v.size() - 1;
        bool correct = true;
        if (y < 0)
            correct = false;
        while (l <= r)
        {
            LL md = v[(l + r) / 2];
            if (((y / md) <= md))
            {
                r = (l + r) / 2 - 1;
                continue;
            }
            if ((y % md) == 0)
            {
                if (m.find(y / md) != m.end())
                {
                    ans += m[y / md] * m[md];
                    break;
                }
            }
            LL sec = y / md;
            if (correct)
            {
                if ((md + sec) >= x)
                    l = (l + r) / 2 + 1;
                else
                    r = (l + r) / 2 - 1;
            }
            else
            {
                if ((md + sec) <= x)
                    l = (l + r) / 2 + 1;
                else
                    r = (l + r) / 2 - 1;
            }
        }
        LL sq = sqrt(y);
        if(m.find(sq) != m.end())
        if ((sq * sq) == y)
        {
            ans += ((m[sq] * (m[sq] - 1))) / 2ll;
        }
        cout << ans << " ";
    }
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