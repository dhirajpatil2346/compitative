#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PII pair<int, int>
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < (n * (n - 1)) / 2; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    // for (auto &val : m)
    // {
    //     cout << val.second << " " << val.first << endl;
    // }
    int need = n - 1;
    vector<int> ans;
    set<PII> q;
    for (auto &val : m)
        q.insert(val);

    while (need > 0)
    {
        auto f = *q.begin();
        q.erase(q.begin());
        // cout << f.first << " " << f.second << endl;
        ans.push_back(f.first);
        if (f.second - need)
            q.insert({f.first, f.second - need});
        need--;
    }
    ans.push_back(*max_element(ans.begin(), ans.end()));
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
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