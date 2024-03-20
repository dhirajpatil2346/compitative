#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<LL> v(m);
    for (auto &val : v)
        cin >> val;
    LL def = m;
    if (v[0] != 1)
        def++;
    LL prv = 1;
    vector<LL> value(m);
    for (int i = 0; i < m; i++)
    {
        prv = 1;
        if (i > 0)
            prv = v[i - 1];
        LL nxt = v[i];
        LL inbet = nxt - prv - 1;
        inbet = max(0ll, inbet);
        def += inbet / d;
        value[i] = inbet / d;
    }
    map<LL, vector<LL>> mp;
    LL ind = 0, valp = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        LL prev = 1, next = n + 1;
        if (i > 0)
            prev = v[i - 1];
        if ((i + 1) < m)
            next = v[i + 1];
        LL inbet = next - prev - 1;
        inbet /= d;
        if (v[i] != 1)
            inbet--;
        mp[inbet].push_back(i);
        cout << i << " " << inbet << endl;
    }
    for (auto &val : mp)
    {
        cout << val.first << " --> ";
        for (auto &valu : val.second)
            cout << valu << " ";
        cout << endl;
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