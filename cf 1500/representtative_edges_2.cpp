#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int f(int ind, int &diff, int last, vector<int> &v)
{
    if (ind == v.size())
        return 0;
    int req = last - diff;
    int ret = 0;
    ret += (req != v[ind]);
    return ret += f(ind + 1, diff, req, v);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    // -201 to 201
    int ans = 1e9;
    for (int first = v[0] - 202; first < v[0] + 202; first++)
    {
        for (int i = -201; i <= 201; i++)
            ans = min(ans, f(0, i, first, v));
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