#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &val : v)
        cin >> val;
    vector<long long> v1 = v;
    sort(v1.begin(), v1.end());
    map<int, set<int>> curro, reqo, curre, reqe;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            curro[v[i]].insert(i), reqo[v1[i]].insert(i);
        else
            curre[v[i]].insert(i), reqe[v1[i]].insert(i);
    }
    for (auto &val : curro)
    {
        int pt = val.first;
        for (auto &pos : val.second)
        {
            if (reqo[pt].size() == 0)
                return false;
            reqo[pt].erase(reqo[pt].begin());
        }
    }
    for (auto &val : curre)
    {
        int pt = val.first;
        for (auto &pos : val.second)
        {
            if (reqe[pt].size() == 0)
                return false;
            reqe[pt].erase(reqe[pt].begin());
        }
    }
    return true;
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}