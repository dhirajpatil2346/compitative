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
    vector<int> index[3];
    for (int i = 0; i < n; i++)
        index[v[i]].push_back(i);
    for (auto &val : index)
        val.push_back(n);
    int cst = 0;
    for (int i = 0; i < n;)
    {
        // cout << i << endl;
        cst++;
        if (v[i] == 0)
        {
            int l = i, r = *upper_bound(index[0].begin(), index[0].end(), i);
            int two = *upper_bound(index[2].begin(), index[2].end(), i);
            if (two < r)
            {
                i = r + 1;
            }
            else if (r == (l + 1))
            {
                i++;
            }
            else
            {
                i = r;
            }
        }
        else
        {
            i = *upper_bound(index[0].begin(), index[0].end(), i) + 1;
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