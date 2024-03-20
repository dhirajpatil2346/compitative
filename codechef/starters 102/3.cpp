#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, ans = 0;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    set<int> s;
    for (auto &val : v)
        s.insert(val);
    sort(v.begin(), v.end());
    map<LL, LL> par;
    for (int i = 0; i < n; i++)
    {
        LL c = v[i];
        for (LL j = 1; j * j <= v[i]; j++)
        {
            if (v[i] % j)
                continue;
            LL fct = v[i] / j;
            if (s.find(j) != s.end())
            {
                par[j]++;
            }
            if ((fct != j) && s.find(fct) != s.end())
            {
                par[fct]++;
            }
        }
        cout << i << "  -->  ";
        for (auto &val : par)
            cout << val.first << " " << val.second << endl;
    }
    for (auto &val : par)
        if (val.first != 1)
            ans = max(ans, val.first * val.second);
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