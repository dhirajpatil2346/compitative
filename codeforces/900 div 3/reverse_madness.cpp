#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    // n len of str
    // cout << " n k " << n << " " << k << endl;
    string s;
    cin >> s;
    // cout << "string s is : " << s << endl;
    vector<int> revInd(n + 1);
    // k len of vp array
    vector<int> a(k), b(k);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    for (int i = 0; i < k; i++)
    {
        int l = a[i], r = b[i];
        while (l <= r)
        {
            revInd[l] = r;
            revInd[r] = l;
            l++, r--;
        }
    }
    int u;
    cin >> u;
    // cout << "q size : " << u << endl;
    vector<int> q(u);
    vector<int> pref(n + 2);
    for (auto &val : q)
        cin >> val;

    sort(q.begin(), q.end());
    // cout << "queries : ";

    int i = 0, j = 0;
    while (i < q.size())
    {
        int x = q[i];
        while (!(x >= a[j] && x <= b[j]))
            j++;
        // now we on good track
        // cout << " i j " << i << " " << j << endl;
        int mini = min(x, a[j] + b[j] - x);
        int maxi = max(x, a[j] + b[j] - x);
        pref[mini]++;
        pref[maxi + 1]--;
        i++;
    }
    for (int i = 1; i < pref.size(); i++)
    {
        pref[i] += pref[i - 1];
    }
    string ans = s;
    // // cout << ans << " " << ans.size() << endl;
    for (int i = 1; i <= n; i++)
    {
        // ind in string is i - 1
        if (pref[i] & 1)
        {
            ans[i - 1] = s[revInd[i] - 1];
        }
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