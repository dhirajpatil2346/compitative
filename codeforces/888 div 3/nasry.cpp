#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

LL costof(LL ind, vector<LL> &cost, vector<LL> &fcost, vector<vector<LL>> &make)
{
    if (fcost[ind] != -1)
        return fcost[ind];
    if (cost[ind] == 0)
        return fcost[ind] = 0;
    if (make[ind].size() == 0)
        return fcost[ind] = cost[ind];
    LL ret = cost[ind];
    LL f = 0;
    for (auto &val : make[ind])
        f += costof(val, cost, fcost, make);
    ret = min(ret, f);
    return fcost[ind] = ret;
}

void solve()
{
    LL n, k;
    cin >> n >> k;
    set<LL> unlimited;
    vector<LL> cost(n + 1), fcost(n + 1, -1);
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    for (int i = 0; i < k; i++)
    {
        LL x;
        cin >> x;
        cost[x] = 0;
        unlimited.insert(x);
    }
    vector<vector<LL>> make(n + 1);
    for (int _ = 1; _ <= n; _++)
    {
        int a;
        cin >> a;
        while ((a--))
        {
            int x;
            cin >> x;
            make[_].push_back(x);
        }
    }
    for (LL i = 1; i <= n; i++)
        costof(i, cost, fcost, make);
    for (int i = 1; i <= n; i++)
        cout << fcost[i] << " ";
    cout << endl;
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