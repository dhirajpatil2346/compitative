#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"


bool solve()
{
    int n;
    cin >> n;
    multiset<int> ns;
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        ns.insert(x);
    }
    vector<int> v;
    for (auto &val : ns)
        v.push_back(val);
    for (int i = 0; i < 2 * n - 1; i++)
    {
        multiset<int> ms = ns;
        vector<pair<int, int>> ans;
        ans.push_back({*(prev(ms.end())), v[i]});
        ms.erase(prev(ms.end()));
        ms.erase(ms.find(v[i]));
        int value = ans[0].first;
        bool can = true;
        while (ms.size() && can)
        {
            int r = *(prev(ms.end()));
            ms.erase(prev(ms.end()));
            int f = value - r;
            // cout << r << " " << f << endl;
            if ((f > r) || (ms.find(f) == ms.end()))
            {
                can = false;
                break;
            }
            ms.erase(ms.find(f));
            ans.push_back({r, f});
            value = r;
        }
        if (can)
        {
            cout << "YES" << endl;
            cout << ans[0].first + ans[0].second << endl;
            for (auto &val : ans)
                cout << val.first << " " << val.second << endl;
            return true;
        }
    }
    return false;
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
        if (!solve())
            cout << "NO" << endl;
    }
    return 0;
}