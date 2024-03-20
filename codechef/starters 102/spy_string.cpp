#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &val : v)
        cin >> val;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int d = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int cd = 0;
            for (int ind = 0; ind < m; ind++)
                cd += (v[i][ind] != v[j][ind]);
            d = max(d, cd);
        }
        mp[d].push_back(i);
    }
    if ((mp.begin())->first <= 1)
        cout << (v[(mp.begin())->second[0]]) << endl;
    else if ((prev(mp.end()))->first > 2)
    {
        cout << -1 << endl;
    }
    else
    {
        // we can make string
        string a = v[mp[2][0]], b = v[mp[2][1]];
        vector<int> v1;
        for (int i = 0; i < m; i++)
            if (a[i] != b[i])
                v1.push_back(i);
        string s = b;
        int d = 0;
        if (v1.size())
        {
            s[v1[0]] = a[v1[0]];
            for (int j = 0; j < n; j++)
            {
                int cd = 0;
                for (int ind = 0; ind < m; ind++)
                    cd += (s[ind] != v[j][ind]);
                d = max(d, cd);
            }
            if (d <= 1)
            {
                cout << s << endl;
                return;
            }
        }
        d = 0;
        s = b;
        if (v1.size() >= 1)
        {
            s[v1[1]] = a[v1[1]];
            for (int j = 0; j < n; j++)
            {
                int cd = 0;
                for (int ind = 0; ind < m; ind++)
                    cd += (s[ind] != v[j][ind]);
                d = max(d, cd);
            }
            if (d <= 1)
            {
                cout << s << endl;
                return;
            }
        }
        cout << -1 << endl;
        return;
    }
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