#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    if ((accumulate(v.begin(), v.end(), 0ll)) % 2ll == 1ll)
    {
        cout << -1 << endl;
        return;
    }
    // for (auto &val : v)
    //     cout << val << " ";
    // cout << endl;
    vector<LL> ret(n);
    vector<LL> even, odd;
    for (auto &val : v)
        if (val & 1ll)
            odd.push_back(val);
        else
            even.push_back(val);
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    // for (auto &val : even)
    //     cout << val << " " << endl;
    int j = 0;
    for (int i = 0; i < (even.size() / 2); i++, j++)
    {
        int x = i, y = even.size() - i - 1;
        ret[j] = (even[x] + even[y]) / 2ll;
        ret[j + n / 2] = ret[j] - even[x];
    }
    for (int i = 0; i < odd.size() / 2; i++, j++)
    {
        int x = i, y = even.size() - i - 1;
        ret[j] = (odd[x] + odd[y]) / 2ll;
        ret[j + n / 2] = ret[j] - odd[x];
    }
    for (auto &val : ret)
        cout << val << " ";
    cout << endl;
    // for (int i = 0; i < n / 2; i++)
    //     cout << ret[i] + ret[i + n / 2] << " " << abs(ret[i] - ret[i + n / 2]) << " ";
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