#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void print(vector<pair<int, int>> &ans)
{
    cout << ans.size() << endl;
    for (auto &val : ans)
    {
        cout << val.first + 1 << " " << val.second + 1 << endl;
    }
}
void positive(vector<LL> &v, vector<pair<int, int>> &ans)
{
    for (int i = 1; i < v.size(); i++)
    {
        ans.push_back({i, i - 1});
        v[i] += v[i - 1];
    }
}
void negative(vector<LL> &v, vector<pair<int, int>> &ans)
{
    for (int i = v.size() - 2; i >= 0; i--)
    {
        ans.push_back({i, i + 1});
        v[i] += v[i + 1];
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    int pos = 0, neg = 0;
    for (auto &val : v)
        if (val > 0)
            pos++;
        else if (val < 0)
            neg++;
    vector<pair<int, int>> ans;
    if (max(pos, neg) <= 12)
    {
        int mx = 0;
        for (int i = 1; i < n; i++)
            if (abs(v[i]) > abs(v[mx]))
                mx = i;
        // cout << mx << endl;
        if (v[mx] <= 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] > 0)
                {
                    ans.push_back({i, mx});
                    v[i] += v[mx];
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] < 0)
                {
                    ans.push_back({i, mx});
                    v[i] += v[mx];
                }
            }
        }
    }
    else
    {
        if (pos >= neg)
        {
            int mx = 0;
            for (int i = 0; i < n; i++)
                if (v[i] > v[mx])
                    mx = i;
            for (int i = 0; i < 12 - neg; i++)
            {
                v[mx] += v[mx];
                ans.push_back({mx, mx});
            }
            for (int i = 0; i < n; i++)
                if (v[i] < 0)
                {
                    v[i] += v[mx];
                    ans.push_back({i, mx});
                }
        }
        else
        {
            int mx = 0;
            for (int i = 0; i < n; i++)
                if (v[i] <= v[mx])
                    mx = i;
            for (int i = 0; i < 12 - pos; i++)
            {
                v[mx] += v[mx];
                ans.push_back({mx, mx});
            }
            for (int i = 0; i < n; i++)
                if (v[i] > 0)
                {
                    v[i] += v[mx];
                    ans.push_back({i, mx});
                }
        }
    }
    pos = 0, neg = 0;
    for (auto &val : v)
        if (val > 0)
            pos++;
        else if (val < 0)
            neg++;
    if (pos > 0)
    {
        positive(v, ans);
    }
    else
    {
        negative(v, ans);
    }
    print(ans);
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