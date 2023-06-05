#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

bool f(int ind, vector<LL> &v, LL req, vector<vector<int>> &dp)
{
    if (req == 0)
        return true;
    if (ind < 0)
        return false;
    if (dp[ind][req] != -1)
        return dp[ind][req];
    bool ret = f(ind - 1, v, req, dp);
    if (v[ind] <= req)
        ret |= f(ind - 1, v, req - v[ind], dp);
    return dp[ind][req] = ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    LL maxi = *max_element(v.begin(), v.end());
    set<LL> s;
    for (int i = 1; i < n; i++)
    {
        LL curr = v[i];
        for (int j = i - 1; j >= 0; j--)
        {
            curr += v[j];
            if (curr > maxi)
                break;
            s.insert(curr);
        }
    }
    int e = 0;
    for (auto &val : v)
        if (s.find(val) != s.end())
            e++;
    cout << e << endl;
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