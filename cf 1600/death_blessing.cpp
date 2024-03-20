#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    deque<pair<LL, LL>> q;
    vector<LL> F(n), s(n);
    for (auto &val : F)
        cin >> val;
    for (auto &val : s)
        cin >> val;
    for (int i = 0; i < n; i++)
    {
        LL x = F[i], y = s[i];
        // cin >> x >> y;
        q.push_back({x, y});
    }
    LL ans = 0;
    while (q.size())
    {
        auto f = q.front(), b = q.back();
        if (f.second <= b.second)
        {
            ans += f.first;
            q.pop_front();
            if (q.size())
                q.front().first += f.second;
        }
        else
        {
            ans += b.first;
            q.pop_back();
            if (q.size())
                q.back().first += b.second;
        }
    }
    cout << ans << endl;
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