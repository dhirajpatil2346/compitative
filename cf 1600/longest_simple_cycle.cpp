#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> endval(n);
    for (auto &val : endval)
        cin >> val;
    vector<LL> a(n), b(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    for (int i = 0; i < n; i++)
        if (a[i] > b[i])
            swap(a[i], b[i]);
    vector<LL> extra(n, 0);
    for (int i = 1; i < n - 1; i++)
        extra[i] = a[i + 1] - 1 + endval[i] - b[i + 1];
    for (int i = 1; i < n; i++)
        extra[i] += extra[i - 1];
    vector<LL> startval(n, 0);
    for (int i = 1; i < n; i++)
        startval[i - 1] = b[i] - a[i];
    vector<int> can = {0};
    for (int i = 1; i < n - 1; i++)
        if (startval[i] == 0)
            can.push_back(i);
    can.push_back(n - 1);
    for (auto &val : endval)
        val--;
    // cout << "startval : ";
    // for (auto &val : startval)
    //     cout << val << " ";
    // cout << endl;
    // cout << "endval : ";
    // for (auto &val : endval)
    //     cout << val << " ";
    // cout << endl;
    LL fans = 0;
    for (int i = 1; i < n; i++)
    {
        LL start = *(prev(lower_bound(can.begin(), can.end(), i))), end = i;
        LL ans = 0;
        ans += 2ll * (end - start);
        ans += (startval[start] + endval[end]);
        ans += extra[end - 1] - extra[start];
        fans = max(fans, ans);
        // cout << i << " " << start << " " << end << " " << startval[start] << " " << endval[end] << " " << ans << endl;
        start = *(prev(lower_bound(can.begin(), can.end(), i))), end = i;
        ans = 0;
        ans += 2ll * (end - start);
        ans += startval[start];
        ans += extra[end] - extra[start];
        if (ans < (startval[i]))
            *(prev(lower_bound(can.begin(), can.end(), i))) = i;

    }
    cout << fans << endl;
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