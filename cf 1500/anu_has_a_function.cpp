#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n), left(n), right(n), track(n);
    for (auto &val : v)
        cin >> val;
    LL curr = 0;
    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] | v[i - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] | v[i + 1];
    for (int j = 0; j < n; j++)
    {
        LL val = left[j] | right[j];
        for (LL i = 63; i >= 0; i--)
            if ((v[j] & (1ll << i)) && (!(val & (1ll << i))))
                track[j] += (1ll << i);
    }
    // for (auto &val : left)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : right)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : track)
    //     cout << val << " ";
    // cout << endl;
    int pos = max_element(track.begin(), track.end()) - track.begin();
    cout << v[pos] << " ";
    for (int i = 0; i < n; i++)
        if (i != pos)
            cout << v[i] << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}