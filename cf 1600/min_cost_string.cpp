#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int cost(string &s)
{
    map<string, int> m;
    for (int i = 0; i < s.length() - 1; i++)
    {
        string h = "";
        h.push_back(s[i]);
        h.push_back(s[i + 1]);
        m[h]++;
    }
    int c = 0;
    for (auto &val : m)
    {
        c += (val.second * (val.second - 1)) / 2;
    }
    return c;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < k; i++)
    {
        v.push_back(i);
        v.push_back(i);
    }
    vector<vector<int>> dp(k, vector<int>(k));
    for (int i = 0; i < v.size() - 1; i++)
        dp[v[i]][v[i + 1]]++;
    for (int _ = v.size(); _ < n; _++)
    {
        int a = v.back(), b = INT_MAX;
        for (int i = 0; i < k; i++)
            if (i != a)
                b = min(b, dp[a][i]);
        if (dp[a][a] < b)
        {
            v.push_back(a);
            dp[a][a]++;
        }
        else
        {
            int f = 0;
            for (int i = 0; i < k; i++)
                if (dp[a][i] == b)
                {
                    f = i;
                }
            v.push_back(f);
            dp[a][f]++;
        }
    }
    string s = "";
    for (int i = 0; i < n; i++)
        s.push_back('a' + v[i]);
    cout << s << endl;
    // cout << cost(s) << endl;
    string h = "aaccbbcab";
    // cout << cost(h) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}