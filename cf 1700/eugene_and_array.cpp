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
    LL i = 0, ans = 0;
    while (i < n)
    {
        if (v[i] == 0)
            continue;
        LL l = i, r = i;
        LL curr = v[i];
        map<LL, LL> m;
        m[0] = i;
        m[curr] = i;
        while (i < n)
        {
            curr += v[i];
            if (m.find(curr) != m.end())
            {
                r = i - 1;
                break;
            }
            else
                m[curr] = i++;
        }
        if (i == n)
        {
            r = i - 1;
        }
        cout << l << " " << r << endl;
        ans += (((r - l + 2ll) * (r - l + 1ll)) / 2ll);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}