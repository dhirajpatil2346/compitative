#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    vector<LL> v;
    LL x = 1;
    while (x <= n)
    {
        v.push_back(x);
        x *= 2ll;
    }
    while (v.back() != n)
    {
        for (int i = v.size() - 2; i >= 0; i--)
        {
            if ((v.back() + v[i]) <= n)
            {
                v.push_back(v.back() + v[i]);
                break;
            }
        }
    }
    reverse(v.begin(), v.end());
    cout << v.size() << endl;
    for (auto &val : v)
        cout << val << " ";
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