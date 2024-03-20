#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<int> parent(10, 1), ranking(10, 1);
set<pair<int, int>> s;
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void us(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return;
    if (ranking[a] < ranking[b])
        swap(a, b);
    parent[b] = find_set(a);
    ranking[a] += ranking[b];
    s.insert({ranking[a], a});
}
void solve()
{
    int n, m;
    cin >> n >> m;
    parent.clear(), ranking.clear(), s.clear();
    for (int i = 0; i <= n; i++)
        parent.push_back(i), ranking.push_back(1);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        us(x, y);
        cout << (*s.rbegin()).first - 1 << endl;
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