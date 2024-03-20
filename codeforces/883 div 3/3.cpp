#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, m, h;
    cin >> n >> m >> h;
    vector<vector<LL>> v(n, vector<LL>(m));
    for (auto &val : v)
        for (auto &valu : val)
            cin >> valu;
    for (auto &val : v)
        sort(val.begin(), val.end());
    vector<pair<LL, LL>> score(n, {0, 0}); // first pt, 2nd penalty
    for (int _ = 0; _ < n; _++)
    {
        vector<LL> org = v[_];
        int pos = -1;
        if (org[0] <= h)
            pos = 0;
        for (int i = 1; i < org.size(); i++)
        {
            org[i] += org[i - 1];
            if (org[i] <= h)
                pos = i;
            // score[_].second += org[i];
        }
        // position till we can traverse
        score[_].first = pos + 1;
        for (int i = 0; i < pos + 1; i++)
        {
            // org[i] += org[i - 1];
            score[_].second += org[i];
        }
    }
    // for (auto &val : score)
    //     cout << val.first << " " << val.second << endl;
    int up = 0;
    for (int i = 1; i < n; i++)
    {
        if (score[i].first > score[0].first)
        {
            up++;
            continue;
        }
        else if (score[i].first < score[0].first)
            continue;
        else if (score[i].second < score[0].second)
            up++;
    }
    cout << up + 1 << endl;
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