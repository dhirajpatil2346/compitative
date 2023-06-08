#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    bool rev = false;
    if (n < m)
    {
        rev = true;
        swap(n, m);
    }
    s.insert({0, 1});
    s.insert({0, 0});
    vector<pair<int, int>> ans;
    ans.push_back({0, 1});
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (s.find({i, j}) != s.end())
                continue;
            s.insert({i, j});
            bool g = true;
            for (auto &val : ans)
            {
                LL x1 = abs(val.first - i);
                x1 *= x1;
                LL y1 = abs(val.second - j);
                y1 *= y1;
                x1 += y1;
                if (x1 == (sqrt(x1) * sqrt(x1)))
                {
                    g = false;
                    break;
                }
            }
            if (g)
            {
                ans.push_back({i, j});
            }
        }
    }
    if (rev)
        for (auto &val : ans)
            swap(val.first, val.second);
    cout << ans.size() << endl;
    for (auto &val : ans)
        cout << val.first << " " << val.second << endl;
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
/*
2 2
0 2
1 1
2 0

*/