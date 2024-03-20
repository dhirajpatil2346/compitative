#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    LL K = k;
    vector<LL> v(n);
    for (int i = 0; i < n; i += 2)
        v[i] = 1;
    for (int i = 1; i < n; i += 2)
        v[i] = 2;
    k -= accumulate(v.begin(), v.end(), 0ll);
    for (int i = 0; (i < n) && (k > 0); i++)
    {
        LL diff = 1e5 - v[i];
        if (diff & 1ll)
            diff--;
        LL can = k;
        if (can & 1)
            can--;
        LL mini = min(can, diff);
        v[i] += mini;
        k -= mini;
    }
    bool fault = false;
    if (v.size() != n)
        fault = true;
    if (accumulate(v.begin(), v.end(), 0ll) != K)
        fault = true;
    LL odd = 0, even = 0;
    for (auto &val : v)
    {
        if (val & 1ll)
            odd++;
        else
            even++;
        if (val >= 1 && val <= 1e5)
            continue;
        fault = true;
    }
    if (odd != even)
        fault = true;
    if (fault)
        cout << -1 << endl;
    else
    {
        for (auto &val : v)
            cout << val << " ";
        cout << endl;
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