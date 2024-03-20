#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> org(n);
    for (auto &val : org)
        cin >> val;
    vector<int> ans;
    ans.push_back(org[0]);
    for (int i = 1; i < n; i++)
    {
        if (org[i] >= org[i - 1])
        {
            ans.push_back(org[i]);
        }
        else
        {
            ans.push_back(org[i] );
            ans.push_back(org[i]);
        }
    }
    cout << ans.size() << endl;
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
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