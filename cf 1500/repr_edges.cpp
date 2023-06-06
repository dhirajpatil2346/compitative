#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, ans = 1e9;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    for (int I = 0; I < n; I++)
    {
        map<pair<int, int>, int> m;
        for (int i = 0; i < I; i++)
        {
            int ele = abs(i - I);
            int diff = v[i] - v[I];
            int g = __gcd(abs(diff), ele);
            ele /= g, diff /= g;
            m[{diff, ele}]++;
        }
        for (int i = I + 1; i < n; i++)
        {
            int ele = abs(i - I);
            int diff = v[I] - v[i];
            int g = __gcd(abs(diff), ele);
            ele /= g, diff /= g;
            m[{diff, ele}]++;
        }
        // cout << I << endl;
        // for (auto &val : m)
        // {
        //     cout << val.first.first << " " << val.first.second << " " << val.second << endl;
        // }
        int maxi = 0;
        for (auto &val : m)
            maxi = max(maxi, val.second);
        maxi++;
        ans = min(ans, n - maxi);
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
/*
aaa


*/