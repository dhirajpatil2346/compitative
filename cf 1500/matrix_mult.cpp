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

void solve()
{
    vector<vector<LL>> v1 = {
     
        {1, 1}};
    vector<vector<LL>>
        v2 = {
        {1, 1},
        {1, 1}};
    v1 = mm(v1, v2);
    for (auto &val : v1)
    {
        for (auto &valu : val)
            cout << valu << " ";
        cout << endl;
    }
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