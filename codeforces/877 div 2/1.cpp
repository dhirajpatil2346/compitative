#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;

    map<LL, vector<LL>> m;
    for (int i = 0; i < n; i++)
    {
        m[v[i]].push_back(i);
    }
    if ((*m.begin()).first < 0)
    {
        cout << (*m.begin()).first << endl;
        return;
    }
    else
    {
        cout << (*m.rbegin()).first << endl;
        return;
    }
    bool g = false;
    for (int i = 0; i < n; i++)
    {
        if (g)
            break;
        for (int j = 0; j < n; j++)
        {
            if (g)
                break;
            if (j == i)
                continue;
            LL x = v[i] - v[j];
            if (m.find(x) == m.end())
                continue;
            for (auto &val : m[x])
                if (val != i && val != j)
                {
                    cout << v[i] << endl;
                    return;
                }
        }
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