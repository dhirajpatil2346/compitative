

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
LL bin(LL a, LL b)
{
    if (b == 0)
        return 1;
    LL res = bin(a, b / 2);
    res = (res * res) % mod;
    if (b & 1)
        res = (res * a) % mod;
    return res;
}

LL f(int sc, int par, vector<vector<int>> &v, vector<bool> &vis, set<pair<int, int>> &s)
{

    if (s.find({sc, par}) != s.end())
        return 0;
    if (vis[sc])
        return 0;
    vis[sc] = true;
    int ret = 1;
    for (auto &child : v[sc])
    {
        if (child == par)
            continue;
        ret += f(child, sc, v, vis, s);
    }
    return ret;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n + 1);
    set<int> proper, improper;
    set<pair<int, int>> s;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back(y);
        v[y].push_back(x);
        if (z)
        {
            s.insert({x, y});
            s.insert({y, x});
        }
        else
        {
            improper.insert(x);
            improper.insert(y);
        }
    }
    for (int i = 1; i <= n; i++)
        if (improper.find(i) == improper.end())
            proper.insert(i);
    cout << "proper is : " << proper.size() << endl;
    LL ans = bin((LL)n, (LL)k);
    cout << ans << endl;
    ans = ((ans - proper.size())) % mod;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << ans << endl;
        if ((proper.find(i) != proper.end()) || (vis[i]))
            continue;
        LL len = f(i, -1, v, vis, s);
        cout << "len for " << i << " "
             << " is : " << len << endl;
        if (len > 0)
            ans -= bin(len, k);
    }
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
/*

3^5 total = 243
eleminate proper singles = 1
net we have 242
now edge faulty is 2 3
so 2 ^ 5 should be eleminated i.e. 242  - 32 = 210
1st testcase
all are proper so 4^4 - single prop = 252


*/