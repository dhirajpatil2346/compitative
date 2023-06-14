#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

bool d(char sc, char par, set<char> &vis, map<char, set<char>> &m)
{
    // cout << sc << endl;
    if (vis.find(sc) != vis.end())
        return true;
    vis.insert(sc);
    bool ret = false;
    if (m.find(sc) != m.end())
        for (auto &child : m[sc])
            ret |= d(child, sc, vis, m);
    return ret;
}

bool cycle(map<char, set<char>> &m)
{
    map<char, int> inc;
    for (auto a = 'a'; a <= 'z'; a++)
        inc[a] = 0;
    for (auto &val : m)
        for (auto &valu : val.second)
            inc[valu]++;
    bool ret = false;
    set<char> vis;
    for (auto &val : m)
        if (inc[val.first] == 0)
            ret &= d(val.first, ' ', vis, m);
    // for (auto &val : vis)
    //     cout << val << " ";
    // cout << endl;
    for (auto &val : m)
    {
        ret |= (vis.find(val.first) == vis.end());
        for (auto &valu : val.second)
        {
            // cout << (vis.find(valu) != vis.end()) << endl;
            ret |= (vis.find(valu) == vis.end());
        }
    }
    // cout << ret << endl;
    return ret;
}

void dfs(char sc, map<char, set<char>> &m, string &curr, set<char> &vis)
{
    if (vis.find(sc) != vis.end())
        return;
    vis.insert(sc);
    for (auto &child : m[sc])
        dfs(child, m, curr, vis);
    curr.push_back(sc);
}
string solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &val : v)
        cin >> val;
    vector<pair<char, char>> vp;
    map<char, set<char>> m;
    for (int i = 0; i < n - 1; i++)
    {
        int j1 = 0, j2 = 0;
        while ((j1 < v[i].length()) && (j2 < v[i + 1].length()) && ((v[i][j1] == v[i + 1][j2])))
            j1++, j2++;
        if ((j1 == v[i].length()))
            continue;
        if ((j2 == v[i + 1].length()))
            return "";
        m[v[i][j1]].insert(v[i + 1][j2]);
    }
    // for (auto &val : m)
    // {
    //     cout << val.first << " --> ";
    //     for (auto &child : val.second)
    //         cout << child << " ";
    //     cout << endl;
    // }
    if (cycle(m))
    {
        // cout << "cycle" << endl;
        return "";
    }
    string ans = "";
    set<char> vis;
    for (auto &val : m)
        dfs(val.first, m, ans, vis);
    reverse(ans.begin(), ans.end());
    // cout << ans << endl;

    for (char a = 'a'; a <= 'z'; a++)
    {
        if (vis.find(a) == vis.end())
        {
            dfs(a, m, ans, vis);
        }
    }
    // cout << ans << endl;
    return ans;
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
        string s = solve();
        if (s.length() == 0 || s.length() != 26)
            s = "Impossible";
        cout << s << endl;
    }
    return 0;
}