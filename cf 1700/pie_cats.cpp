#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    vector<pair<int, int>> vp;
    for (auto &val : m)
        vp.push_back({val.second, val.first});
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    for (auto &val : vp)
        cout << val.first << " " << val.second << endl;
    int l = 1, r = n - 1, ans = 1;
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(i);
    while (l <= r)
    {
        int mid = (l + r) / 2;
        bool clr = true;
        set<int> cs = s;
        int j = 0;
        for (; (j < vp.size());)
        {
            cout << "mid is " << mid << " j is : " << j << endl;
            cout << " -- > " << endl;
            if (!clr)
                break;
            int i = *cs.begin();
            cs.erase(i);
            int pos = i;
            cout << pos << " ";
            for (int k = 1; k < vp[j].first; k++)
            {
                int next = pos + mid;
                if (cs.lower_bound(next) != cs.end())
                {
                    next = *cs.lower_bound(next);
                    cout << next << " ";
                    cs.erase(next);
                    pos = next;
                }
                else
                {
                    cout << " next error " << next << endl;
                    clr = false;
                    break;
                }
            }
            cout << endl;
            j++;
        }

        if (clr)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans - 1 << endl;
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
4 3 2 4 3 2 4 3 1 4
*/