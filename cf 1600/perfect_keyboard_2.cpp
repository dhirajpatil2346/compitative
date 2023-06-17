#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

void dfs(set<char> &vis, char sc, string &ans, map<char, set<char>> &m)
{
    if (vis.find(sc) != vis.end())
        return;
    vis.insert(sc);
    ans.push_back(sc);
    for (auto &child : m[sc])
        dfs(vis, child, ans, m);
}

void solve()
{
    string s;
    cin >> s;
    map<char, set<char>> m, me;
    for (auto ch = 'a'; ch <= 'z'; ch++)
    {
        set<char> st;
        m[ch] = st;
        me[ch] = st;
    }
    for (int i = 0; i < s.length() - 1; i++)
        m[s[i]].insert(s[i + 1]), me[s[i + 1]].insert(s[i]);

    vector<pair<int, char>> vp;
    for (auto &val : me)
        vp.push_back({val.second.size(), val.first});
    sort(vp.begin(), vp.end());
    string ans = "";
    set<char> vis;
    for (auto &val : vp)
        dfs(vis, val.second, ans, m);
    bool fault = false;
    int pos = -1;
    for (int i = 0; i < ans.length(); i++)
        if (s[0] == ans[i])
        {
            pos = i;
            break;
        }
    for (int i = 1; i < s.length(); i++)
    {
        if (ans[pos] == s[i])
            continue;
        if (((pos + 1) < ans.length()) && ans[pos + 1] == s[i])
            pos++;
        else if (((pos - 1) >= 0) && ans[pos - 1] == s[i])
            pos--;
        else
        {
            fault = true;
            break;
        }
    }
    if (fault)
        cout << "NO" << endl;
    else
        cout << "YES" << endl
             << ans << endl;
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



*/