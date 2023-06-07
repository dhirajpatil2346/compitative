#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL f(LL curr, vector<LL> &dp, LL &k)
{
    if (curr < 0)
        return 0;
    if (curr == 0)
        return dp[0] = 1;
    if (dp[curr] != -1)
        return dp[curr];
    LL ret = 0;
    for (int i = k;; i++)
    {
        if ((curr - i) < 0)
            break;
        LL p = i;
        cout << curr << " " << curr - i << endl;
        ret += f(curr - i, dp, k);
    }
    return dp[curr] = ret;
}
void solve()
{
    LL n, k, q;
    cin >> n >> k >> q;
    vector<LL> track;
    LL last = 0;
    for (LL i = 0; i < n; i++)
    {
        LL x;
        cin >> x;
        if (x <= q)
        {
            last++;
        }
        else
        {
            track.push_back(last);
            last = 0;
        }
    }
    if (last > 0)
        track.push_back(last);
    LL ans = 0;
    LL mx = *max_element(track.begin(), track.end());
    vector<LL> dp(mx + 1, -1);

    for (auto &val : track)
    {
        if (val < k)
            continue;
        LL p = (val - k + 1);
        ans += ((p) * (p + 1)) / 2;
    }
    cout << ans << endl;
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
1 3
10 11
15 17
1 2 4 5
30 
60
*/