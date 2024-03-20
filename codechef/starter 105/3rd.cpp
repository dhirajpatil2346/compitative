#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

bool f(int i, string &a, string &b, char last, int used, vector<pair<int, int>> &lastu, vector<vector<vector<int>>> &dp)
{
    if (used > 300)
        return -1;
    if (i == a.length())
        return true;
    int l = 0;
    if (last == '1')
        l = 1;
    if (dp[i][l][used] != -1)
        return dp[i][l][used];
    bool ret = false;
    // don't insert
    if (last != a[i])
    {
        // yes u r free
        ret |= f(i + 1, a, b, a[i], used, lastu, dp);
        if (ret)
        {
            if (lastu[i].first < used)
            {
                lastu[i] = {used, 0};
            }
        }
    }
    // insert
    if (b.back() != a[i] && last != b.front())
    {
        ret |= f(i + 1, a, b, a[i], used + 1, lastu, dp);
        if (ret)
        {
            if (lastu[i].first < used)
            {
                lastu[i] = {used, 1};
            }
        }
    }
    return dp[i][l][used] = ret;
}

bool solve()
{
    int n, m = 2;
    cin >> n;
    string a, b = "01";
    cin >> a;
    vector<int> ans;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
            continue;
        if (a[i - 1] == '0')
            return false;
        if (a[i] == '1')
            return false;
        ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
    return true;
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
        if (solve())
        {
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}