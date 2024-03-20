#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
#define Endl "\n"
const LL mod = 1e9 + 7;
pair<int, int> dp[(int)2e5 + 1][2][2][2][4];

pair<int, int> f(int i, int a, int b, int c, int last, vector<int> &v)
{
    // base condition
    if (i == v.size())
    {
        // cout << last << " -> ";
        // cout << a << " " << b << " "<< c << endl;
        if (last != 1)
            return {0, a + b + c};
        if (v.back() != v[0])
            return {0, 1e9};
        return {0, a + b + c};
    }
    pair<int, int> p = {-1, -1};
    if (dp[i][a][b][c][last] != p)
        return dp[i][a][b][c][last];
    pair<int, int> ret = {0, 1e9};
    if (v[i] == v[i - 1])
    {
        auto p = f(i + 1, true, b, c, 1, v);
        if (p.second <= ret.second)
            ret = {1, p.second};
        p = f(i + 1, a, true, c, 2, v);
        if (p.second <= ret.second)
            ret = {2, p.second};
        if (b == true)
        {
            p = f(i + 1, a, b, true, 3, v);
            if (p.second <= ret.second)
                ret = {3, p.second};
        }
    }
    else
    {
        pair<int, int> p = {0, 0};
        if (last != 1)
        {
            p = f(i + 1, true, b, c, 1, v);
            if (p.second <= ret.second)
                ret = {1, p.second};
        }
        if (last != 2)
        {
            p = f(i + 1, a, true, c, 2, v);
            if (p.second <= ret.second)
                ret = {2, p.second};
        }
        if (last != 3 && b)
        {
            p = f(i + 1, a, b, true, 3, v);
            if (p.second <= ret.second)
                ret = {3, p.second};
        }
    }
    // cout << i << " " << last << " " << ret.first << " " << ret.second << endl;
    return dp[i][a][b][c][last] = ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    for (int m = 0; m < 4; m++)
                        dp[i][j][k][l][m] = {-1, -1};
    f(1, 1, 0, 0, 1, v);
    vector<int> ans;
    int last = 1;
    int a = 1, b = 0, c = 0;
    for (int i = 1; i < n; i++)
    {
        ans.push_back(last);
        if (last == 1)
            a = true;
        if (last == 2)
            b = true;
        if (last == 3)
            c = true;
        auto p = dp[i][a][b][c][last];
        last = p.first;
    }
    ans.push_back(last);
    cout << dp[1][1][0][0][1].second << endl;
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
}
signed main()
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