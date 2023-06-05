#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    map<LL, vector<LL>> m;
    m[0].push_back(-1);
    LL lu = -1, curr = 0;
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        curr += v[i];
        if (m.find(curr) != m.end())
        {
            if (lower_bound(m[curr].begin(), m[curr].end(), lu) - m[curr].begin() != m[curr].size())
            {
                e++;
                lu = i - 1;
            }
        }
        m[curr].push_back(i);
    }
    cout << e << endl;
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