#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    int mx = v.back();
    int size2 = count(v.begin(), v.end(), mx);
    int size1 = n - size2;
    if (size1 == 0)
    {
        cout << -1 << endl;
        return;
    }
    cout << size1 << " " << size2 << endl;
    for (auto &val : v)
    {
        if (val != mx)
            cout << val << " ";
    }
    cout << endl;
    while (size2--)
        cout << mx << " ";
    cout << endl;
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