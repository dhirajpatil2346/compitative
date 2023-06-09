#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
vector<vector<LL>> mm(vector<vector<LL>> &v1, vector<vector<LL>> &v2)
{
    vector<vector<LL>> ret(v1.size(), vector<LL>(v2[0].size()));
    for (int i = 0; i < ret.size(); i++)
        for (int j = 0; j < ret[0].size(); j++)
        {
            LL r = 0;
            for (int k = 0; k < v1[0].size(); k++)
            {
                r = (r + v1[i][k] * v2[k][j]) % mod;
            }
            ret[i][j] = r;
        }
    return ret;
}

vector<vector<LL>> binexpo(vector<vector<LL>> v, LL p)
{
    vector<vector<LL>> f = {{3, 1}, {1, 3}};
    if (p == 1)
        return f;
    vector<vector<LL>> res = binexpo(v, p / 2);
    res = mm(res, res);
    if (p & 1)
        res = mm(res, f);
    return res;
}

void solve()
{
    LL n;
    cin >> n;
    if (n == 0)
    {
        cout << 1 << endl;
        return;
    }
    // return 1;
    vector<vector<LL>> ini = {{3, 1}, {1, 3}};
    // if ((n - 1) > 0)
    ini = binexpo(ini, n);
    cout << ini[0][0] << endl;
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