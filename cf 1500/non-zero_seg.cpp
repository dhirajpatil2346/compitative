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
    LL curr = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        curr += v[i];
        cout << i << " " << curr << endl;
        if (curr == 0)
        {
            curr = v[i];
            e++;
        }
    }
    cout << e << endl;
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