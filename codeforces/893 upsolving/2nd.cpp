#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, m, d;
    cin >> n >> m >> d;
    vector<LL> v(m);
    LL def = m;
    for (auto &val : v)
        cin >> val;
    def += (v[0] != 1);
    for (int i = 0; i < m; i++)
    {
        if (v[i] == 1)
            continue;
        LL prv = 1, nxt = v[i];
        if (i > 0)
            prv = v[i - 1];
        LL inbet = nxt - prv - 1;
        def += inbet / d;
    }
    LL nxt = n + 1, prv = v.back();
    LL inbet = nxt - prv - 1;
    def += inbet / d;
    for (int i = 0; i < m; i++)
    {
        LL prevcost = 1;
        prv = 1, nxt = n + 1;
        if (i > 0)
            prv = v[i - 1];
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