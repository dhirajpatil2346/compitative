#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> m;
    while (n--)
    {
        int i, j;
        cin >> i >> j;
        m[i].push_back(j);
    }
    vector<pair<int, int>> v;
    for (auto &val : m)
    {
        int k = val.first;
        sort(val.second.begin(), val.second.end());
        reverse(val.second.begin(), val.second.end());
        for (auto &valu : val.second)
        {
            v.push_back({k, valu});
        }
    }
    int ans = 0;
    reverse(v.begin(), v.end());

    int x = v[k - 1].first, y = v[k - 1].second;
    for (auto &val : v)
    {
        if (val.first == x && val.second == y)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}