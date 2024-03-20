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
    LL maxi = (n * (n + 1ll)) / 2ll;
    if (v.back() > maxi)
    {
        cout << "NO" << endl;
        return;
    }
    if (v.back() != maxi)
        v.push_back(maxi);
    LL res = 0;
    set<LL> s;
    if (v[0] > n)
    {
        res = v[0];
    }
    else
    {
        s.insert(v[0]);
    }
    // cout << "h1" << endl;
    for (int i = 1; i < v.size(); i++)
    {
        if ((v[i] - v[i - 1]) > n)
        {
            if (res != 0)
            {
                cout << "NO" << endl;
                return;
            }
            res = v[i] - v[i - 1];
        }
        else
        {
            if (s.find(v[i] - v[i - 1]) != s.end())
            {
                if (res != 0)
                {
                    cout << "NO" << endl;
                    return;
                }
                res = v[i] - v[i - 1];
            }
            else
            {
                s.insert(v[i] - v[i - 1]);
            }
        }
    }
    // cout << "j" << endl;
    if (s.size() == n)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        // cout << "ll" << res << endl;
        // for (auto &val : s)
        //     cout << val << " ";
        // cout << endl;
        LL z = 0;
        for (int i = 1; i <= n; i++)
            if (s.find(i) == s.end())
                z += i;
        if (z != res)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
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