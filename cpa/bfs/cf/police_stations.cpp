// https://codeforces.com/contest/796/problem/D
#include <bits/stdc++.h>
using namespace std;

vector<int> v[400000];
bool vis[400000]={false};
int ps[400000];
bool po[400000] = {false};
map<pair<int, int>, bool> used;
void dfs(int source, int parent, int level, int d)
{
    if (vis[source] || level > d)
    {
        return;
    }
    vis[source] = true;
    if (po[source] || parent == -1)
    {
    }
    else
    {
        po[source] = true;
        used[{source, parent}] = true;
        used[{parent, source}] = true;
    }
    for (auto &child : v[source])
    {
        if (child == parent || vis[child])
        {
            continue;
        }
        dfs(child, source, level + 1, d);
    }
}

int main()
{
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 0; i < k; i++)
    {
        cin >> ps[i];
        po[ps[i]] = true;
    }
    vector<pair<int, int>> avail;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        avail.push_back({x, y});
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 0; i < k; i++)
    {
        dfs(ps[i], -1, 0, d);
    }
    vector<int> ans;
    int c = 1;
    for (auto &val : avail)
    {
        if (used[{val.first, val.second}] || used[{val.second, val.first}])
        {
            c++;
        }
        else
        {
            ans.push_back(c);
            c++;
        }
    }
    cout << ans.size() << endl;
    for (auto &val : ans)
    {
        cout << val << " ";
    }
    return 0;
}