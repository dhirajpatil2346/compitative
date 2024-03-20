#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

bool fault = false;
const LL mod = 998244353;

LL f(int sc, vector<vector<bool>> &twodvis, int need, vector<vector<int>> &v)
{
    // need = 0 for even
    // need = 1 for odd
    if (twodvis[sc][need])
        return 1;
    twodvis[sc][need] = true;
    LL ret = 1;
    if (need == 0)
        ret++;
    for (auto &child : v[sc])
        ret = (ret * f(child, twodvis, abs(1 - need), v)) % mod;
    return ret;
}

void dfs(int sc, int par, vector<bool> &vis, vector<int> &prev, int curr, vector<vector<int>> &v)
{
    if (fault)
        return;
    if (prev[sc] == 0)
        prev[sc] = curr;
    if (vis[sc])
    {
        int diff = curr - prev[sc];
        if (diff % 2)
        {
            fault = true;
        }
        return;
    }
    vis[sc] = true;
    for (auto &child : v[sc])
        if (child != par)
        {
            if (par == 0 && vis[child])
                continue;
            dfs(child, sc, vis, prev, curr + 1, v);
        }
}

LL solve()
{
    fault = false;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<bool> vis(n + 1, false);
    vector<int> prev(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (fault)
            return 0;
        else if (vis[i])
            continue;
        else
            dfs(i, 0, vis, prev, 1, v);
    vector<vector<bool>> twodvis(n + 1, vector<bool>(2, false));
    LL ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (twodvis[i][0] == false)
        {
            LL even = f(i, twodvis, 0, v);
            LL odd = (even + f(i, twodvis, 1, v)) % mod;
            ans = (ans * odd) % mod;
        }
    }
    return ans;
    return 1;
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
        cout << solve() << endl;
    }
    return 0;
}
/*
12
8 7
2 3
3 4
4 5
5 2
6 7
7 8
8 6

1 0

2 1
1 2

3 3
1 2
2 3
1 3

3 2
2 3
3 1

4 4
1 2
2 3
3 4
4 1

4 4
1 2
2 3
3 1
4 1

6 9
1 4
1 5
1 6
2 4
2 5
2 6
3 4
3 5
3 6

100000 0

1000 5
55 56
56 57
57 58
58 59
59 55

11 11
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 1

10 12
1 2
2 3
3 4
4 1
1 5
5 6
6 7
7 1
1 8
8 9
9 10
10 1
*/