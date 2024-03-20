#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int bin(vector<int> &p)
{
    return 1;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n * m);
    for (auto &val : v)
        cin >> val;
    map<int, stack<int>> s;
    for (int i = 0; i < n * m; i++)
        s[v[i]].push(i);
    sort(v.begin(), v.end());
    vector<vector<int>> mat(n, vector<int>(m)), ans(n, vector<int>(m));
    for (int track = 0, i = 0, j = 0; track < n * m; track++)
    {
        mat[track / m][track % m] = v[track];
    }
    // for (auto &val : mat)
    // {
    //     for (auto &valu : val)
    //         cout << valu << " ";
    //     cout << endl;
    // }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = s[mat[i][j]].top();
            s[mat[i][j]].pop();
        }
    }
    // for (auto &val : ans)
    // {
    //     for (auto &valu : val)
    //         cout << valu << " ";
    //     cout << endl;
    // }
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        set<int> p;
        for (int j = 0; j < m; j++)
        {
            int z = 0;
            for (auto &val : p)
                if (val < ans[i][j])
                    z++;
            p.insert(ans[i][j]);
            c += z;
        }
    }
    cout << c << endl;
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