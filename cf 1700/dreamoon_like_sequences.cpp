#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL d, m, f = 0;
    cin >> d >> m;
    vector<LL> facts;

    while (d > 0)
    {
        LL mn = min(d, 1ll << f);
        d -= mn;
        facts.push_back(mn + 1ll);
        f++;
    }

    vector<LL> track(facts.size());
    track.back() = 1ll;
    for (int i = track.size() - 2; i >= 0; i--)
        track[i] = (track[i + 1] * facts[i + 1]) % m;
    // for (auto &val : facts)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : track)
    //     cout << val << " ";
    // cout << endl;
    LL ans = 0;
    for (int i = 0; i < track.size(); i++)
        ans = (ans + ((facts[i] - 1ll) * track[i] % m)) % m;
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