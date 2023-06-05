#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    map<pair<int, int>, int> m;
    pair<int, int> ans = {0, 1e9};
    m[{0, 0}] = -1;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            x--;
        else if (s[i] == 'R')
            x++;
        else if (s[i] == 'U')
            y++;
        else
            y--;
        // cout << "  ->  " << ans.first << " " << ans.second << endl;
        if (m.find({x, y}) != m.end())
        {
            if ((ans.second - ans.first) > (i - m[{x, y}]))
            {
                ans = {m[{x, y}], i};
            }
        }
        // cout << i << "  -->   " << x << " " << y << endl;
        // cout << "  ->  " << ans.first << " " << ans.second << endl;
        m[{x, y}] = i;
    }
    if (ans.second == 1e9)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans.first + 2 << " " << ans.second + 1 << endl;
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