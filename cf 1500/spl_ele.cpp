#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    int ans = 0;
    for (int _ = 0; _ < n; _++)
    {
        unordered_map<int, int> m;
        bool got = false;

        // first loop
        m[0] = -1;
        int sum = 0;
        for (int i = 0; (i < _) && (got == false); i++)
        {
            sum += v[i];
            if (m.find(sum) == m.end())
                m[sum] = i;
            int r = sum - v[_];
            if (m.find(r) == m.end())
                continue;
            int pos = m[r];
            if (abs(i - pos) >= 2)
            {
                got = true;
            }
        }

        m.clear();
        // second loop
        if (_ < n - 1)
        {
            m[0] = _;
            int sum = v[_ + 1];
            m[sum] = _ + 1;
            for (int i = _ + 2; (i < n) && (got == false); i++)
            {
                sum += v[i];
                if (m.find(sum) == m.end())
                    m[sum] = i;
                int r = sum - v[_];
                if (m.find(r) == m.end())
                    continue;
                int pos = m[r];
                if (abs(i - pos) >= 2)
                {
                    got = true;
                }
            }
        }

        if (got)
            ans++;
    }
    cout << ans << endl;
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