#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, x;
    cin >> n >> x;
    set<int> s;
    set<int> v[x];
    int mex = 0;
    while (n--)
    {
        int j;
        cin >> j;
        v[j % x].push_back(j);
        s.insert(j);
        auto it = v[mex % x].lower_bound( mex);
        if (it != v[mex % x].end())
        {
            s.erase(s.find(*it));
        }
    }
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