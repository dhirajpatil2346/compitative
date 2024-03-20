#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

void top(int sc, vector<int> &v, vector<bool> &vis, vector<int> &topo)
{
    if (vis[sc])
        return;
    topo.push_back(sc);
    vis[sc] = true;
    top(v[sc], v, vis, topo);
}

void dfs1(int sc, int curr, vector<int> &v, map<int, int> &prev, vector<int> &ans)
{
    if (prev.find(sc) != prev.end())
    {
        ans[sc] = prev[sc] - curr;
        return;
    }
    prev[sc] = curr;
    dfs1(v[sc], curr + 1, v, prev, ans);
}

class Solution
{
public:
    vector<int> countVisitedNodes(vector<int> &v)
    {
        int n = v.size();
        vector<bool> vis(n, false);
        map<int, int> prev;
        vector<int> ans(n, n);
        for (int i = 0; i < n; i++)
            if (prev.find(i) == prev.end())
                dfs1(i, 0, v, prev, ans);
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    return 0;
}