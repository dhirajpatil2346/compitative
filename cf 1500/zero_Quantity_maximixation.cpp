#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int lcm(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a * b) / __gcd(a, b);
}

void solve()
{
    int n, e = 0;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (auto &val : v1)
        cin >> val;
    for (auto &val : v2)
        cin >> val;
    map<pair<int, int>, int> mp1;
    for (int i = 0; i < n; i++)
    {
        int a = v1[i], b = v2[i];
        int lc = __gcd(abs(a), abs(b));
        cout << a << " " << b << " " << lc << endl;
        if (a == 0 || b == 0)
        {
            mp1[{a, b}]++;
            continue;
        }
        else
        {
            a /= lc, b /= lc;
            if (a < 0 && b < 0)
            {
                a = abs(a), b = abs(b);
            }
            if (a < 0 && b > 0)
            {
                a = abs(a), b *= (-1);
            }
            mp1[{a, b}]++;
        }
    }
    for (auto &val : mp1)
        cout << val.first.first << " " << val.first.second << " --> " << val.second << endl;
    int ans = 0;
    for (auto &val : mp1)
        ans = max(ans, val.second);
    cout << ans << endl;
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