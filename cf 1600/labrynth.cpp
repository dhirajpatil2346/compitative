#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int n, m, dr, dc, x, y;
vector<string> v;
void solve()
{
    set<pair<pair<int, int>, pair<int, int>>> mp;
    cin >> n >> m >> dr >> dc >> x >> y;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    dr--, dc--;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    queue<pair<int, int>> q;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}