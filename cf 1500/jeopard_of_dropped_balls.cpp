#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using vl = vector<LL>;
using vi = vector<int>;
using vvl = vector<vl>;
using vvi = vector<vi>;
#define endl "\n"

int give(int sr, int sc, int &n, int &m, vvi &v, vvi &par, vvi &cnt)
{
    if (sr >= n)
        return sc;
    if (sc < 0)
        return 1;
    if (sc >= m)
        return m;
    if (cnt[sr][sc] >= 2)
        return par[sr][sc];
    cnt[sr][sc]++;
    int org = v[sr][sc];
    v[sr][sc] = 2;
    if (org == 1)
        return par[sr][sc] = give(sr, sc + 1, n, m, v, par, cnt);
    else if (org == 2)
        return par[sr][sc] = give(sr + 1, sc, n, m, v, par, cnt);
    return par[sr][sc] = give(sr, sc - 1, n, m, v, par, cnt);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vvi v(n, vi(m)), cnt(n, vi(m, 0)), par(n, vi(m, -1));
    for (auto &val : v)
        for (auto &valu : val)
            cin >> valu;
    while (k--)
    {
        int sr = 0, sc;
        cin >> sc;
        sc--;
        cout << give(sr, sc, n, m, v, par, cnt) + 1 << endl;
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