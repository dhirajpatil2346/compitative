#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<LL> v1(n), v2(m);
    multiset<LL> s;
    for (auto &val : v1)
        cin >> val;
    for (auto &val : v2)
        cin >> val;
    for (auto &val : v1)
        s.insert(val);
    // sort(v2.begin(), v2.end());
    for (auto &val : v2)
    {
        s.erase(s.begin());
        s.insert(val);
    }
    LL sum = 0;
    for (auto &val : s)
        sum += val;
    cout << sum << endl;
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