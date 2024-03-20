#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<LL> can(n);
    for (int i = 0; i < n; i++)
        can[i] = v[i] / 3;
    LL l = 1, r = 1e11;
    LL ans = 1;
    while (l <= r)
    {
        LL m = (l + r) / 2;
        vector<LL> v1 = v;
        for (int i = n - 1; i >= 2; i--)
        {
            if (v1[i] < m)
                break;
            LL extra = v1[i] - m;
            LL moves = min(can[i], extra / 3);
            v1[i] -= moves * 3;
            v1[i - 1] += moves;
            v1[i - 2] += 2 * moves;
        }
        // cout<<m<<endl;
        bool correct = ((*min_element(v1.begin(), v1.end())) >= m);
        if (correct)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
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