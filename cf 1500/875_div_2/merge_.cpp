#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    vector<int> first(n, 1), second(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            first[i] += first[i - 1];
        if (b[i] == b[i - 1])
            second[i] += second[i - 1];
    }
    map<int, int> f, s;
    for (int i = 0; i < n; i++)
        if (f.find(a[i]) == f.end())
            f[a[i]] = first[i];
        else
            f[a[i]] = max(f[a[i]], first[i]);
    for (int i = 0; i < n; i++)
        if (s.find(b[i]) == s.end())
            s[b[i]] = second[i];
        else
            s[b[i]] = max(s[b[i]], second[i]);
    int ans = 0;
    for (auto &val : f)
        ans = max(ans, val.second);
    for (auto &val : s)
        ans = max(ans, val.second);
    for (auto &val : f)
    {
        if (s.find(val.first) == s.end())
            continue;
        ans = max(ans, f[val.first] + s[val.first]);
    }
    cout << ans << endl;
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