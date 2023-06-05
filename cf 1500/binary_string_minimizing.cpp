#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<char> s(n);
    for (auto &val : s)
        cin >> val;
    vector<LL> track;
    for (LL i = 0; i < n; i++)
        if (s[i] == '0')
            track.push_back(i);
    LL l = 0;
    vector<int> dest;
    for (LL i = 0; i < track.size(); i++)
    {
        if (k == 0)
            dest.push_back(track[i]);
        int need = track[i] - l;
        if (k >= need)
        {
            dest.push_back(l++);
            k -= need;
        }
        else
        {
            dest.push_back(track[i] - k);
            k = 0;
        }
    }
    vector<char> ans(n, '1');
    for (LL i = 0; i < dest.size(); i++)
        ans[dest[i]] = '0';
    for (auto &val : ans)
        cout << val;
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