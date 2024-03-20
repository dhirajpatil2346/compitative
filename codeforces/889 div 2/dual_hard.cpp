#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void neg(vector<LL> &v)
{
    int mn = 1;
    int n = v.size();
    for (int i = 2; i < n; i++)
        if (v[i] < v[mn])
            mn = i;
    vector<pair<int, int>> ans;
    if (v[mn] != 0)
        if (v[0] > v[mn])
        {
            ans.push_back({mn, mn});
            v[mn] += v[mn];
        }
    for (int i = n - 2; i >= 0; i--)
    {
        if (ans.size() > 50)
            break;
        if (v[i] <= v[i + 1])
            continue;
        while ((v[i] + v[0]) > v[i + 1])
        {
            if (ans.size() > 50)
                break;
            ans.push_back({0, 0});
            v[0] += v[0];
        }
        ans.push_back({i, 0});
        v[i] += v[0];
    }
    cout << ans.size() << endl;
    for (auto &val : ans)
        cout << val.first + 1 << " " << val.second + 1 << endl;
}
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    bool clear = true;
    for (int i = 1; i < n; i++)
        if (v[i] < v[i - 1])
            clear = false;
    if (clear)
    {
        cout << 0 << endl;
        return;
    }
    int pos = 0;
    for (int i = 0; i < n; i++)
        if (v[i] > 0)
            pos++;
    if (pos == 0)
    {
        neg(v);
    }
    vector<pair<int, int>> ans;
    vector<pair<int, pair<int, int>>> ans1;
    int p = 0;
    for (int i = 1; i < n - 1; i++)
        if (v[i] > v[p])
            p = i;
    if (v[p] > 0)
    {
        while ((v[p] + v.back()) < 0)
        {
            if (ans.size() > 50)
                break;
            v[p] *= 2ll;
            ans.push_back({p, p});
        }
        if (v.back() < 0)
        {
            ans.push_back({n - 1, p});
            v.back() += v[p];
        }
    }
    if (v[p] > v.back())
    {
        v.back() += v[p];
        ans.push_back({n - 1, p});
    }
    for (int i = 1; i < n; i++)
    {
        if (ans.size() > 50)
            break;
        if (v[i] >= v[i - 1])
            continue;
        while ((v[n - 1] + v[i]) < v[i - 1])
        {
            if (ans.size() > 50)
                break;
            ans.push_back({n - 1, n - 1});
            v[n - 1] += v[n - 1];
        }
        v[i] += v[n - 1];
        ans.push_back({i, n - 1});
    }
    cout << ans.size() << endl;
    for (auto &val : ans)
    {
        cout << val.first + 1 << " " << val.second + 1 << endl;
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