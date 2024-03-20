#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n - 1);
    for (auto &val : v)
        cin >> val;
    if (v.front() != 1)
    {
        vector<LL> p = {1};
        for (auto &val : v)
            p.push_back(val);
        v = p;
        set<LL> s;
        s.insert(1);
        for (int i = 1; i < v.size(); i++)
            s.insert(v[i] - v[i - 1]);
        if (*(s.rbegin()) > n || s.size() != n)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
        return;
    }
    LL maxi = n * (n + 1ll);
    maxi /= 2;
    if (v.back() > maxi)
    {
        cout << "NO" << endl;
        return;
    }
    // cout << "h"
    //      << " " << maxi << endl;
    if (v.back() != maxi)
    {
        v.push_back(maxi);
        set<LL> s;
        s.insert(1);
        for (int i = 1; i < v.size(); i++)
            s.insert(v[i] - v[i - 1]);
        if (*(s.rbegin()) > n || s.size() != n)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
        return;
    }
    LL res = 0;
    LL cnt = 0;
    for (int i = 1; i < v.size(); i++)
        if ((v[i] - v[i - 1]) > n)
            cnt++;
    if (cnt > 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i < v.size(); i++)
    {
        if ((v[i] - v[i - 1]) > n)
            res = v[i] - v[i - 1];
    }
    // cout << res << endl;
    if (res != 0)
    {
        set<int> s;
        s.insert(v[0]);
        for (int i = 1; i < n; i++)
            if ((v[i] - v[i - 1]) <= n)
                s.insert(v[i] - v[i - 1]);
        LL z = 0;
        for (int i = 1; i <= n; i++)
            if (s.find(i) == s.end())
                z += i;
        if (z != res)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        return;
    }
    else
    {
        map<LL, LL> m;
        int y = 0;
        for (auto &val : m)
        {
            if (val.second >= 2)
                y++;
        }
        if (y >= 2)
        {
            cout << "NO" << endl;
            return;
        }
        for (auto &val : m)
        {
            if (val.second >= 2)
            {
                res = val.first;
            }
        }
        set<LL> s;
        LL z = 0;
        for (int i = 1; i <= n; i++)
            if (s.find(i) == s.end())
                z += i;
        if (z != res)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
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