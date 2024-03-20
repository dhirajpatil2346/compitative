#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, m;
    cin >> n >> m;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    vector<int> query(m);
    for (auto &val : query)
        cin >> val;
    vector<LL> ans(n - 2);
    for (LL i = 0, ele = n - 1; i < ans.size(); i++, ele--)
    {
        ans[i] += ((ele * (ele - 1)) / 2);
        if (i > 0)
            ans[i] += ans[i - 1];
    }
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
    for (auto &val : query)
    {
        int pos = lower_bound(ans.begin(), ans.end(), val) - ans.begin();
        cout << v[pos] << endl;
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
/*
nc2 = n! / (n-2)!2! => n * (n-1) / 2
*/