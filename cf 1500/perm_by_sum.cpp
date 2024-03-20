#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int solve()
{
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int N = r - l + 1;
    if ((((n * (n + 1)) / 2) < s) || (((N) * (N + 1)) / 2) > s)
        return -1;
    // cout << "passed" << endl;
    int R = n;
    set<int> vis;
    vector<int> ans;
    for (int _ = 0; _ < (r - l + 1); _++)
    {
        int mand = (N * (N - 1)) / 2;
        while (vis.find(R) != vis.end())
            R--;
        ans.push_back(min(R, s - mand));
        s -= ans.back();
        vis.insert(ans.back());
        // cout << ans.back() << endl;
        N--;
    }
    if (s != 0)
        return -1;
    vector<int> as(n);
    l--, r--;
    for (int i = l, j = 0; i <= r; i++, j++)
        as[i] = ans[j];
    for (int i = 0, j = 1; i < n;)
    {
        if (vis.find(j) != vis.end())
        {
            j++;
            continue;
        }
        if (as[i] != 0)
        {
            i++;
            continue;
        }
        as[i++] = j++;
    }
    for (auto &val : as)
        cout << val << " ";
    cout << endl;
    return 0;
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
        int p = solve();
        if (p == -1)
            cout << p << endl;
    }
    return 0;
}