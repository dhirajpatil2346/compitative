#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

LL f(int curr, vector<LL> &k, vector<LL> &h, vector<LL> &dp)
{
    if (curr >= (k.size() - 1))
        return 0;
    if (dp[curr] != -1)
        return dp[curr];
    LL ret = 1e9;
    ret = (ret / 2ll) * (1ll + ret);
    LL time = 0, health = 0;
    time += k[curr + 1] - k[curr];
    health = h[curr + 1];
    if (time < health)
        return ret;
    time = health;
    LL cans = (time * (2ll + (time - 1ll))) / 2ll;
    ret = min(ret, cans + f(curr + 1, k, h, dp));
    for (LL i = curr + 2ll; i < k.size(); i++)
    {
        time += h[i] - h[i - 1];
        health += k[i];
        if (time < health)
            break;
        cans = (time * (2ll + (time - 1ll))) / 2ll;
        ret = min(ret, cans);
    }
    return dp[curr] = ret;
}

void solve()
{
    LL n;
    cin >> n;
    vector<LL> k(n + 1), h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    vector<LL> comp = h;
    for (int i = k.size() - 2; i > 0; i--)
    {
        LL timediff = k[i + 1] - k[i];
        if (timediff >= comp[i + 1])
            continue;
        // cout << i << " " << comp[i + 1] - (k[i + 1] - k[i]) << endl;
        comp[i] = max(comp[i], comp[i + 1] - (k[i + 1] - k[i]));
    }
    LL ans = 0;
    for (int i = 1; i < comp.size(); i++)
    {
        LL diff = k[i] - k[i - 1];
        LL cans = 0;
        if (diff < comp[i])
        {
            comp[i] = comp[i - 1] + diff;
            LL N = comp[i] - comp[i - 1], a = comp[i - 1] + 1ll, d = 1ll;
            // cout << " ->> " << N << " " << a << endl;
            cans = (N * (2 * a + (N - 1ll))) / 2ll;
            // cout << "  -> " << i << " " << cans << endl;
        }
        else
        {
            LL f = comp[i];
            cans = (f * (2ll + (f - 1ll))) / 2ll;
        }
        ans += cans;
        // cout << i << " " << ans << endl;
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

    for (auto &val : comp)
        cout << val << " ";
    cout << endl;
    vector<LL> dp(n + 1, -1);
    LL sum = k.back();
    LL ans = ((sum) * (2ll + (sum - 1ll))) / 2ll;
    ans = min(ans, f(0, k, h, dp));
    for (int i = 1; i < k.size() - 1; i++)
    {
        LL time = k[i];
    }

*/