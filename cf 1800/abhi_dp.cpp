#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL f(LL ind, LL &k, vector<LL> &rates, vector<LL> &strategy, vector<LL> &dp)
{
    if (ind >= rates.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    LL ret = -1e12;
    // not use
    if (strategy[ind] == 0)
    {
        ret = max(ret, f(ind + 1, k, rates, strategy, dp));
    }
    else if (strategy[ind] == 1)
    {
        ret = max(ret, rates[ind] + f(ind + 1, k, rates, strategy, dp));
    }
    else
    {
        // s == -1 // buy
        ret = max(ret, (-1ll) * rates[ind] + f(ind + 1, k, rates, strategy, dp));
    }

    // use
    if ((ind + k) <= rates.size())
    {
        LL comm = 0;
        for (int i = k / 2; i < k; i++)
        {
            comm += rates[ind + i];
        }
        ret = max(ret, comm + f(ind + k, k, rates, strategy, dp));
    }
    return dp[ind] = ret;
}
int Solution(vector<int> rates, vector<int> strategy, int k)
{
    vector<LL> r, s;
    for (auto &val : rates)
        r.push_back(val);
    for (auto &val : strategy)
        s.push_back(val);
    LL K = k;
    vector<LL> dp(rates.size(), -1);
    f(0, K, r, s, dp);
    for (auto &val : dp)
        cout << val << " ";
    cout << endl;
    return dp[0];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> strategy(n), rates(n);
    for (auto &val : rates)
        cin >> val;
    for (auto &val : strategy)
        cin >> val;
    int k;
    cin >> k;
    cout << Solution(rates, strategy, k) << endl;
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