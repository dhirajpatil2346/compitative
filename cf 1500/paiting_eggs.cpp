#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<pair<LL, LL>> vp(n);
    for (auto &val : vp)
        cin >> val.first >> val.second;
    if (n == 1)
    {
        if (vp[0].first <= vp[0].second)
        {
            if (vp[0].first <= 500)
                cout << "A" << endl;
            else
                cout << -1 << endl;
        }
        else
        {
            if (vp[0].second <= 500)
                cout << "G" << endl;
            else
                cout << -1 << endl;
        }
        return;
    }
    vector<LL> p(n), s(n);
    p[0] = vp[0].first;
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + vp[i].first;
    for (int i = n - 2; i >= 0; i--)
        s[i] = s[i + 1] + vp[i + 1].second;
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (abs(p[i] - s[i]) <= 500)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i <= pos; i++)
            cout << "A";
        for (int i = pos + 1; i < n; i++)
            cout << "G";
        cout << endl;
    }
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