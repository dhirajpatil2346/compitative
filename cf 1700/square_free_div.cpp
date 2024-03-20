#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int j = 2;
        int r = 1;
        while (x > 1 && (j * j <= x))
        {
            int f = 0;
            if (x % j)
            {
                j++;
                continue;
            }
            while (x % j == 0)
            {
                f++;
                x /= j;
            }
            if (f & 1)
                r *= j;
            j++;
        }
        if (x > 1)
            r *= x;
        v.push_back(r);
    }
    int c = 0;
    set<int> s;
    for (auto &val : v)
    {
        if (s.find(val) != s.end())
        {
            c++;
            s.clear();
            s.insert(val);
        }
        else
            s.insert(val);
        // cout << val << " " << s.size() << endl;
    }
    if (s.size() > 0)
        c++;
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