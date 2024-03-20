#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<LL> cm(k + 5, 0);
    for (auto &val : v)
        cm[1]++, cm[val + 1]--;
    for (int i = 1; i < cm.size(); i++)
        cm[i] += cm[i - 1];
    vector<LL> pre(k + 1);
    for (int i = 1; i < pre.size(); i++)
        pre[i] = i;
    for (int i = 2; i < pre.size(); i++)
        if (pre[i] == i)
            for (int j = i; j < pre.size(); j += i)
                pre[j] = i;
    map<LL, LL> m1, m2;

    for (int i = 1; i < cm.size(); i++)
    {
        if (cm[i] == 0)
            break;
        int val = i;
        while (val != 1)
        {
            m1[pre[val]] += cm[i];
            val /= pre[val];
        }
    }
    for (int i = 2; i <= k; i++)
    {
        int val = i;
        while (val != 1)
        {
            m2[pre[val]]++;
            val /= pre[val];
        }
    }
    cout << "m1" << endl;
    for (auto &val : m1)
        cout << val.first << " " << val.second << endl;
    cout << "m2" << endl;
    for (auto &val : m2)
        cout << val.first << " " << val.second << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}