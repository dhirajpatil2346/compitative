#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

bool f(int i, string &a, string &b, char last, vector<vector<int>> &dp)
{
    if (i == a.length())
        return true;
    int l = 0;
    if (last == '1')
        l = 1;
    if (dp[i][l] != -1)
        return dp[i][l];
    bool ret = false;
    // don't insert
    if (last != a[i])
    {
        // yes u r free
        ret |= f(i + 1, a, b, a[i], dp);
    }
    // insert
    if (b.back() != a[i] && last != b.front())
    {
        ret |= f(i + 1, a, b, a[i], dp);
    }
    return dp[i][l] = ret;
}

bool solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    bool fault = false;
    for (int i = 1; i < m; i++)
        if (b[i] == b[i - 1])
            fault = true;
    if (fault)
    {
        bool p = true;
        for (int i = 1; i < n; i++)
            if (a[i] == a[i - 1])
                p = false;
        return p;
    }
    vector<vector<int>> dp(n + 5, vector<int>(3, -1));
    return f(1, a, b, a[0], dp);
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
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}