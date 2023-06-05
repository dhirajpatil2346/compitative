#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool cmp(string &s1, string &s2)
{
    return s1.length() >= s2.length();
}
void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &val : v)
        cin >> val;
    vector<int> par(26, -1);
    vector<vector<int>> g(26);
    for (int i = 0; i < n; i++)
        for (auto &val : v[i])
            g[val - 97].push_back(i);
    set<int> vis;
    set<int> visind;
    int p = 1;
    for (int i = 0; i < 26; i++)
    {
        if (vis.find(i) != vis.end())
            continue;
        vis.insert(i);
        set<char> q, vc;
        for (auto &val : g[i])
        {
            for (auto &chars : v[val])
                q.insert(chars);
        }
        while (q.size())
        {
            char f = *q.begin();
            if (vc.find(f) != vc.end())
                continue;
            q.erase(q.find(f));
            vc.insert(f);
            if (par[f - 97] == -1)
                par[f - 97] = p;
            // cout << f << endl;
            for (auto &child : g[f - 97])
            {
                if (visind.find(child) != visind.end())
                    continue;
                // cout << i << " " << child << endl;
                visind.insert(child);
                for (auto &ch : v[child])
                {
                    if (vc.find(ch) != vc.end())
                        continue;
                    q.insert(ch);
                }
            }
        }
        p++;
    }
    set<int> ans;
    for (auto &val : par)
        if (val != -1)
            ans.insert(val);
    cout << ans.size() << endl;
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