#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int f(int i, int j, string &a, string &b, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (a[i] == b[j])
        return dp[i][j] = 1 + f(i - 1, j - 1, a, b, dp);
    return dp[i][j] = max(f(i - 1, j, a, b, dp), f(i, j - 1, a, b, dp));
}
void solve()
{
    string a, b;
    cin >> a >> b;
    int n1 = a.length(), n2 = b.length();
    vector<vector<int>> dp(n1, vector<int>(n2));
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = 1;
                if (i > 0 && j > 0)
                    dp[i][j] += dp[i - 1][j - 1];
            }
            else
            {
                int m1 = -1, m2 = -1;
                if (i > 0)
                    m1 = dp[i - 1][j];
                if (j > 0)
                    m2 = dp[i][j - 1];
                if (m1 >= m2)
                    dp[i][j] = m1;
                else
                    dp[i][j] = m2;
            }
        }
    string ans = "";

    int i = n1 - 1, j = n2 - 1;
    while (i >= 0 && j >= 0)
    {
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i--, j--;
        }
        else
        {
            int m1 = -1, m2 = -1;
            if (i > 0)
                m1 = dp[i - 1][j];
            if (j > 0)
                m2 = dp[i][j - 1];
            if (m1 >= m2)
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
/*
10 5
2 3 0 0 0 2 3 1 1 0 
7 
1 2
1 3 
1 7 
1 10 
2 7 
2 6 
3 8
*/