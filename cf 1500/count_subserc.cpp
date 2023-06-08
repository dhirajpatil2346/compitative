#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<LL> f(vector<LL> &v1)
{
    vector<LL> p1;
    int n = v1.size();
    int i = 0;
    while (i < n)
    {
        if (v1[i] == 0)
        {
            i++;
            continue;
        }
        LL o = 0;
        while (i < n && v1[i] == 1)
            i++, o++;
        p1.push_back(o);
    }
    return p1;
}
void filldp(vector<LL> &dp, vector<LL> &p)
{
    for (auto &val : p)
    {
        LL x = val, j = 1;
        while (x > 0)
        {
            dp[x] += j;
            x--, j++;
        }
    }
}
void solve()
{
    LL n, m, k;
    cin >> n >> m >> k;
    vector<LL> v1(n), v2(m), dp1(n + 1, 0), dp2(m + 1, 0);
    vector<pair<LL, LL>> facts;
    LL sq = sqrt(k);
    for (LL i = 1; i <= sq; i++)
    {
        if (k % i)
            continue;
        LL sec = k / i;
        if (i == (k / i))
        {
            facts.push_back({i, k / i});
        }
        else
        {
            facts.push_back({i, k / i});
            facts.push_back({k / i, i});
        }
    }
    for (auto &val : v1)
        cin >> val;
    for (auto &val : v2)
        cin >> val;
    vector<LL> p1 = f(v1), p2 = f(v2);
    filldp(dp1, p1), filldp(dp2, p2);
    LL ans = 0;
    for (auto &val : facts)
    {
        if (val.first > n || val.second > m)
            continue;
        ans += dp1[val.first] * dp2[val.second];
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
_ _ _ D
A ++ D
AB+D
ABCD
ABAD

AC+D
ACAD
ACBD

AD+D
ADAD
ADBD
ADCD

B ++ D
BA+D
BABD
BACD

BC+D
BCAB
BCBD

BD+D
BDAD
BDCA
BDBD

C ++ D
CA+D
CABD
CACD

CB+D
CBAD
CBCD

CD+D
CDAD
CDBD
CDAD
*/
/*
1332
*/