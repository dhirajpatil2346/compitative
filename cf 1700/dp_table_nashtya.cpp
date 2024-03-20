#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
map<string, int> m;
map<int, string> rev;
void sieve()
{
    m["1110111"] = 0, m["0010010"] = 1,
    m["1011101"] = 2, m["1011011"] = 3,
    m["0111010"] = 4, m["1101011"] = 5,
    m["1101111"] = 6, m["1010010"] = 7,
    m["1111111"] = 8, m["1111011"] = 9;
    for (auto &val : m)
        rev[val.second] = val.first;
}
int cost(string &a, string &b)
{
    // from a to b
    LL c = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '1' && b[i] == '0')
            return -1;
        c += (a[i] != b[i]);
    }
    return c;
}

int f(int ind, vector<string> &v, int k, vector<vector<int>> &dp)
{
    if (ind == v.size())
        if (k == 0)
            return 88;
        else
            return -1;
    if (dp[ind][k] != 10)
        string curr = v[ind];
    int start = 0;
    int ret = -1;
    string curr = v[ind];
    if (m.find(curr) != m.end())
        start = m[curr];
    for (int i = start; i <= 9; i++)
    {
        int c = cost(curr, rev[i]);
        if (c == -1)
            continue;
        if (c <= k)
        {
            int got = f(ind + 1, v, k - c, dp);
            if (got != -1)
            {
                ret = i;
            }
        }
    }
    return dp[ind][k] = ret;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    for (auto &val : v)
        cin >> val;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // base case
    int start = 0;
    int ret = -1;
    string curr = v[n - 1];
    if (m.find(curr) != m.end())
        start = m[curr];
    // for i = n -1
    for (int i = start; i <= 9; i++)
    {
        int c = cost(curr, rev[i]);
        if (c == -1)
            continue;
        if (c <= k)
            dp[n - 1][c] = i;
    }
    // for (int i = 0; i <= k; i++)
    //     cout << dp[n - 1][i] << " ";
    // cout << endl;
    // build table from n - 2 to n
    for (int I = n - 2; I >= 0; I--)
    {
        start = 0;
        ret = -1;
        curr = v[I];
        if (m.find(curr) != m.end())
            start = m[curr];
        for (int i = 0; i <= 9; i++)
        {
            int c = cost(curr, rev[i]);
            if (c == -1)
                continue;
            for (int j = c; j <= k; j++)
            {
                int got = dp[I + 1][j - c];
                if (got != -1)
                    if (got != -1)
                        dp[I][j] = i;
            }
        }
    }
    // for (int i = 0; i <= k; i++)
    //     cout << dp[0][i] << " ";
    // cout << endl;
    if (dp[0][k] == -1)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        // cout << i << " " << k << " ";
        cout << dp[i][k];
        int val = dp[i][k];
        k -= cost(v[i], rev[val]);
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    solve();
    return 0;
}