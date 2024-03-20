#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    if (v[0] > n)
    {
        cout << "NO" << endl;
        return;
    }
    vector<int> pre(n, 0);
    for (auto &val : v)
    {
        pre[0]++;
        if (val < n)
            pre[val]--;
    }
    bool clr = true;
    for (int i = 1; i < n; i++)
        pre[i] += pre[i - 1];
    for (int i = 0; i < n; i++)
    {
        if (pre[i] != v[i])
            clr = false;
    }
    if (clr)
        cout << "YES" << endl;
        else 
    cout << "NO" << endl;
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