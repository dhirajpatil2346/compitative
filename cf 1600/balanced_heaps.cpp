#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

void handle(int ind, vector<LL> &v)
{
}

void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<LL> can;
    for (auto &val : v)
        can.push_back(val / 3ll);
    set<pair<pair<LL, int>, LL>> s;
    for (int i = 2; i < n; i++)
        s.insert({{v[i], i}, can[i]});
    while (s.size())
    {
        auto it = prev(s.end());
        auto p = *it;
        s.erase(it);
        int ind = p.first.second;
        if (p.first.first != v[ind])
            continue;
        if (p.second == 0)
            continue;
        cout << p.first.first << endl;
        while (can[ind] && ((v[ind] - v[ind - 1])) >= 2)
        {
            can[ind]--;
            v[ind] -= 3;
            v[ind - 1]++;
            v[ind - 2]++;
        }
        if (can[ind] != 0)
            s.insert({{v[ind], ind}, can[ind]});
    }
    cout << *min_element(v.begin(), v.end()) << endl;
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
/*
3 3 7 100
5 4 3 100
5 6 4 97
7 7 1 97

*/
/*
1 2 10 100
1 4 11 97
3 5 8 97
3 7 9 94
5 8 6 94

1 2 10 100
1 8 13 91
7 11 4 91
7 17 7 82


1 2 3 4 5 6 
1 2 5 5 2 6
1 4 6 2 2 6
3 5 3 2 2 6

    if(i and j differ by 3)
    i by 2 i+1 by 3 , j by -3 , j-1 by -2
// 3 5 3 4 3 3
2 2 5 8
4 3 2 8
4 5 3 5


1 2 3 4 5 6
1 4 6 4 3 3
3 5 3 4 3 3
*/