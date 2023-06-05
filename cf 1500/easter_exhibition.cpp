#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void f(vector<pair<LL, LL>> &vp)
{
    LL n = vp.size();
    vector<LL> x, y;
    for (auto &val : vp)
        x.push_back(val.first);
    for (auto &val : vp)
        y.push_back(val.second);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    // for (auto &val : x)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : y)
    //     cout << val << " ";
    // cout << endl;
    vector<LL> xsum = x, ysum = y;
    for (int i = 1; i < x.size(); i++)
        xsum[i] += xsum[i - 1];
    for (int i = 1; i < y.size(); i++)
        ysum[i] += ysum[i - 1];
    vector<LL> t1(n), t2(n);
    for (LL i = 0; i < n; i++)
    {
        LL e1 = i + 1;
        LL e2 = n - e1;
        LL sum1 = xsum[i];
        LL r1 = x[i] * e1;
        t1[i] += abs(r1 - sum1);
        LL sum2 = xsum.back() - xsum[i];
        LL r2 = e2 * x[i];
        t1[i] += abs(r2 - sum2);
    }
    for (LL i = 0; i < n; i++)
    {
        LL e1 = i + 1;
        LL e2 = n - e1;
        LL sum1 = ysum[i];
        LL r1 = y[i] * e1;
        t2[i] += abs(r1 - sum1);
        LL sum2 = ysum.back() - ysum[i];
        LL r2 = e2 * y[i];
        t2[i] += abs(r2 - sum2);
    }
    LL mini = *min_element(t1.begin(), t1.end());
    set<LL> s1, s2;
    for (int i = 0; i < n; i++)
    {
        if (t1[i] == mini)
        {
            s1.insert(x[i]);
        }
    }
    mini = *min_element(t2.begin(), t2.end());
    // for (auto &val : t2)
    //     cout << val << " ";
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (t2[i] == mini)
        {
            s2.insert(y[i]);
        }
    }
    // cout << endl
    //      << endl;
    // for (auto &val : s1)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : s2)
    //     cout << val << " ";
    // cout << endl;

    // cout << 1386603165975904 / (-532147443 + 722460568 + 1) << endl;
    cout << (*s1.rbegin() - *s1.begin() + 1) * (*s2.rbegin() - *s2.begin() + 1) << endl;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<LL, LL>> vp(n, {-1, -1});
    for (auto &val : vp)
    {
        cin >> val.first >> val.second;
    }
    f(vp);
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