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
    vector<bool> red(n, false);
    priority_queue<pair<int, int>> s;
    for (int i = 0; i < n; i++)
        s.push({v[i], i});
    int cst = 0;
    while (s.size())
    {
        auto p = s.top();
        s.pop();
        if (v[p.second] != p.first)
            continue;
        int ind = p.second;
        if (red[ind] == false)
        {
            cst++;
            red[ind] = true;
        }
        for (int curr = ind; curr > 0; curr--)
        {
            if ((red[curr - 1] == true) || (v[curr] == 0))
                break;

            v[curr]--;
            red[curr - 1] = true;
            s.push({v[curr], curr});
        }
        for (int curr = ind; curr < (n - 1); curr++)
        {
            if ((red[curr + 1] == true) || (v[curr] == 0))
                break;
            v[curr]--;
            s.push({v[curr], curr});
            red[curr + 1] = true;
        }
    }
    cout << cst << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}