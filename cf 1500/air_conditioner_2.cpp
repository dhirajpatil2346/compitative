#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool cmp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    if (p1.second.first != p2.second.first)
        return p1.second.first < p2.second.first;
    return p1.second.second >= p2.second.second;
}
bool solve()
{
    int n, t;
    cin >> n >> t;
    vector<pair<int, pair<int, int>>> v(n + 1);
    v[0] = {0, {t, t}};
    for (int i = 1; i <= n; i++)
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    sort(v.begin(), v.end(), cmp);
    int l = t, h = t;
    for (int i = 1; i <= n; i++)
    {
        int time = v[i].first - v[i - 1].first;
        l -= time, h += time;
        if ((v[i].second.first > h) || (v[i].second.second < l))
            return false;
        l = max(l, v[i].second.first), h = min(v[i].second.second, h);
        if (l >= h)
            swap(l, h);
    }
    return true;
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}