#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    map<LL, LL> m;
    for (int i = 0; i < n; i++)
    {
        LL c;
        cin >> c;
        m[c]++;
    }
    set<LL> s;
    for (auto &val : m)
    {
        s.insert(val.first);
        if (val.second == 1)
            continue;
        s.insert((-1ll) * val.first);
    }
    cout << s.size() << endl;
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