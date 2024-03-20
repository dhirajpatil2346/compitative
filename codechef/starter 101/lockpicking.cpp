#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

LL vx(char a, char b)
{
    int a1 = a - '0', a2 = b - '0';
    int mod = 10;
    // int forw
    int i1 = a1;
    int frw = 0, bcw = 0;
    // cout << a1 << " " << a2 << " ";
    while (i1 != a2)
    {
        i1++;
        i1 %= mod;
        frw++;
    }
    i1 = a1;
    while (a1 != a2)
    {
        a1--;
        a1 = (a1 + mod) % mod;
        bcw++;
    }
    return min(frw, bcw);
}

LL f(int ind, int ki, string &a, string &b, vector<vector<LL>> &dp)
{
    if (ki == b.length())
        return 0;
    if (ind >= a.length())
        return 1e8;
    if (dp[ind][ki] != -1)
        return dp[ind][ki];
    return dp[ind][ki] = vx(a[ind], b[ki]) + f(ind + 1, ki + 1, a, b, dp);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    // a is string
    // b is key
    LL mn = 1e9;
    vector<vector<LL>> dp(n + 1, vector<LL>(m + 1, -1));
    for (int i = 0; i < n; i++)
        mn = min(mn, f(i, 0, a, b, dp));
    // for (char i = '0'; i <= '9'; i++)
    //     for (char j = '0'; j <= '9'; j++)
    //         cout << i << " " << j << " " << vx(i, j) << endl;
    cout << mn << endl;
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