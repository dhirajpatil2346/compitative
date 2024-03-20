#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool cmp(pair<LL, LL> &p1, pair<LL, LL> &p2)
{
    if (p1.first != p2.first)
        return p1.first > p2.first;
    return p1.second < p2.second;
}
void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<LL> v(n);
    for (auto &val : v)
    {
        cin >> val;
        val %= k;
    }
    set<pair<LL, LL>> s;
    for (LL i = 0; i < n; i++)
    {
        s.insert({v[i], i});
    }
    vector<pair<LL, LL>> vp;
    for (auto &val : s)
        vp.push_back(val);
    for (auto &val : vp)
        if (val.first == 0)
            val.first = k;
    sort(vp.begin(), vp.end(), cmp);
    // for (auto &val : vp)
    // {
    //     cout << val.first << " " << val.second << endl;
    // }
    for (auto &val : vp)
        cout << val.second + 1 << " ";
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
/*
2 5 3 5
2 2 3 5
2 2 3 2
2 2 0 2

*/