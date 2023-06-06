#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.second <= p2.second;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vp[i] = {a, b};
    }
    sort(vp.begin(), vp.end(), cmp);
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