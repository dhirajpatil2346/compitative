#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> m;
    vector<vector<int>> v(n + 1);
    vector<int> lvl(n + 1, 1e9);
    vector<int> flux(n + 1, 0);
    for (auto i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        m[{a, b}] = i, m[{b, a}] = i;
        if (a == 1 || b == 1)
        {
            lvl[1] = min(lvl[1], i);
        }
    }
    // cout << endl;
    queue<int> q;
    q.push(1);
    vector<bool> vis(n + 1, false);
    vis[1] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (auto &child : v[f])
        {
            if (vis[child])
                continue;
            vis[child] = true;
            q.push(child);
            lvl[child] = m[{child, f}];
            // cout << child << " " << lvl[child] << endl;
            flux[child] = flux[f];
            if (lvl[child] < lvl[f])
            {
                flux[child] += 1;
            }
        }
    }
    // cout << endl;
    cout << *max_element(flux.begin(), flux.end()) + 1 << endl;
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
(bi + bj) % ai = 0
i know bi
x = aj
bj = x * ai - bi
aj * ai > bi
bi + bj = ai
bi + bj = x * ai
x * ai - bi = bj
*/