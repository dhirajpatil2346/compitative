#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL f(int ind, LL c, vector<LL> &stairs, vector<LL> &lift, bool prevlift, vector<vector<LL>> &dist)
{
    LL ret = 1e12;
    if (ind <= 0)
        return dist[ind][prevlift] = 0;
    bool org = prevlift;
    if (dist[ind][prevlift] != -1)
        return dist[ind][prevlift];
    // take lift
    LL lft = 0;
    if (!prevlift)
        lft += c;
    prevlift = true;
    lft += (lift[ind - 1] + f(ind - 1, c, stairs, lift, prevlift, dist));
    // go by stairs
    prevlift = false;
    LL str = stairs[ind - 1] + f(ind - 1, c, stairs, lift, prevlift, dist);
    ret = min(str, lft);
    // cout << ind << " " << ret << endl;
    return dist[ind][org] = ret;
}
void solve()
{
    LL n, c;
    cin >> n >> c;
    vector<LL> stairs(n), lift(n);
    for (int i = 0; i < n - 1; i++)
        cin >> stairs[i];
    for (int i = 0; i < n - 1; i++)
        cin >> lift[i];
    vector<vector<LL>> dist(n, vector<LL>(2, -1));
    // cout << f(n - 1, c, stairs, lift, false, dist) << endl;
    for (int i = 0; i < n; i++)
    {

        f(i, c, stairs, lift, 0, dist);
    }
    for (int i = 0; i < n; i++)
        cout << dist[i][0] << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}