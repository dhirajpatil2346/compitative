#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, L, R;
    cin >> n >> L >> R;
    map<int, int> m;
    for (int i = 0; i < L; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    for (int i = 0; i < R; i++)
    {
        int x;
        cin >> x;
        m[x]--;
    }
    int l = 0, r = 0;
    for (auto &val : m)
        if (val.second >= 0)
            l += val.second;
        else
            r += abs(val.second);
    if (l == r)
    {
        cout << l << endl;
    }
    else
    {
        // cout << "h" << endl;
        if (l > r)
        {
            LL ans = 0;
            for (auto &val : m)
            {
                if (l == r)
                    break;
                if (val.second <= 0)
                    continue;
                int diff = l - r;
                if (diff > val.second)
                {
                    ans += val.second / 2;
                    l -= abs(val.second) / 2;
                }
                else
                {
                    ans += diff / 2;
                    l = r;
                }
            }
            ans += max(l, r);
            cout << ans << endl;
        }
        else
        {
            LL ans = 0;
            for (auto &val : m)
            {
                if (l == r)
                    break;
                if (val.second >= 0)
                    continue;
                int diff = r - l;
                if (diff > val.second)
                {
                    ans += abs(val.second) / 2;
                    r -= abs(val.second / 2);
                }
                else
                {
                    ans += diff / 2;
                    r = l;
                }
            }
            ans += max(l, r);
            cout << ans << endl;
        }
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
        solve();
    return 0;
}