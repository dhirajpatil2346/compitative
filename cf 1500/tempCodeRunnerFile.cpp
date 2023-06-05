#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    set<LL> org, s;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    for (auto &val : v)
        org.insert(val);
    for (int i = 0; i < n - 1; i++)
        s.insert(abs(v[i + 1] - v[i]));
    LL f = 0;
    for (auto &val : s)
        f += val;
    if (n == 2 || org.size() == 1 || f == 0)
    {
        cout << 0 << endl;
        return;
    }
    bool sat = true;
    set<LL> ns;
    for (int i = 1; i < n; i++)
        ns.insert((f + v[i] - v[i - 1]) % f);
    if (ns.size() == 1 && *ns.begin() >= 0)
    {
        cout << 0 << endl;
        return;
    }
    if (ns.size() != 1)
        sat = false;
    LL p = *ns.begin();
    if (p == 0)
    {
        p = *max_element(v.begin(), v.end());
    }
    if (ns.size() == 1 && f < *max_element(v.begin(), v.end()))
    {
        if (2 * f < *max_element(v.begin(), v.end()))
        {
            sat = false;
        }
        else
            f *= 2;
    }
    if (f == *max_element(v.begin(), v.end()))
    {
        f *= 2;
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] != (v[i - 1] + p) % f)
        {
            sat = false;
            break;
        }
    }
    if (!sat)
    {
        cout << -1 << endl;
        return;
    }

    cout << f << " " << p << endl;
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