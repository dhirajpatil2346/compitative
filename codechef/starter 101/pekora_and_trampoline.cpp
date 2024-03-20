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
    vector<LL> vis_needed(n), vis_got(n);
    for (int i = 0; i < n; i++)
        vis_needed[i] = v[i] - 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
            continue;
        // he can give from +2 to +v[i]+i
        // so vis_got[i+2]++, vis_got[v[i]+i+1]--;
        if ((i + 2) < n)
            vis_got[i + 2]++;
        if ((v[i] + i + 1) < n)
            vis_got[v[i] + i + 1]--;
    }
    // for (auto &val : vis_got)
    //     cout << val << " ";
    // cout << endl;
    for (int i = 1; i < n; i++)
        vis_got[i] += vis_got[i - 1];
    for (int i = 0; i < n - 1; i++)
    {
        if (vis_got[i] <= vis_needed[i])
            continue;
        // vis_got[i] > vis_needed[i]
        LL diff = vis_got[i] - vis_needed[i];
        vis_got[i] -= diff;
        vis_got[i + 1] += diff;
    }
    LL sum = 0;
    for (int i = 0; i < n; i++)
        sum += max(0ll, vis_needed[i] - vis_got[i]);
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