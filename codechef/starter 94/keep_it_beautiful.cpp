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
    int i = 1;
    string ans = "1";
    vector<int> curr = {v[0]};
    while (i < n && v[i] >= curr.back())
        curr.push_back(v[i++]), ans.push_back('1');
    for (; i < n; i++)
        if (v[i] >= curr.back())
            ans.push_back('1'), curr.push_back(v[i]);
        else if (v[i] <= curr.front())
        {
            curr.push_back(v[i++]), ans.push_back('1');
            break;
        }
        else
            ans.push_back('0');
    for (; i < n; i++)
        if (v[i] <= curr.front() && v[i] >= curr.back())
            curr.push_back(v[i]), ans.push_back('1');
        else
            ans.push_back('0');
    // for (auto &val : curr)
    //     cout << val << " ";
    // cout << endl;
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