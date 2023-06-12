#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL bin(LL a, LL p)
{
    LL c = 1;
    while (p > 0)
    {
        if (p & 1)
        {
            c *= a;
            if (c >= 1e16)
                return 0;
        }
        if (c >= 1e8)
            return 0;
        c *= c;
        if (c >= 1e16)
            return 0;
        p >>= 1;
    }
    return c;
}
LL solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;

    sort(v.begin(), v.end());
    // for (auto &val : v)
    //     cout << val << " ";
    // cout << endl;
    if (n == 1)
        return abs(v[0] - 1);
    else if (n == 2)
    {
        LL ac = accumulate(v.begin(), v.end(), 0ll);
        return abs(2 - min(2ll, ac));
    }
    else if (n == 3)
    {
        char ch;
        cin >> ch;
        LL A = 2, ans = accumulate(v.begin(), v.end(), 0ll) - n;
        while (true)
        {
            LL f = bin(A, n - 1);
            if (f == 0)
                break;
            if (f <= 2 * v.back())
                A++;
            else
                break;
        }
        for (LL a = 1; a <= A; a++)
        {
            if (a > 0)
            {
                LL cval = 1, ca = 0;
                for (int i = 0; i < n; i++, cval *= a)
                {
                    if (ca >= ans)
                        break;
                    ca += abs(v[i] - cval);
                }
                ans = min(ans, ca);
            }
        }
        return ans;
    }
    LL A = 2, ans = accumulate(v.begin(), v.end(), 0ll) - n;
    if (n > 64)
        return ans;
    bool can = true;
    for (LL a = 2; can;)
    {
        LL cval = 1, ca = 0;
        for (int i = 0; (i < n) && can; i++, cval *= a)
        {
            if (ca >= ans)
                break;
            ca += abs(v[i] - cval);
            if (ca >= ans)
            {
                can = false;
                break;
            }
        }
        // cout << a << " " << ca << endl;
        if (ca >= ans)
            break;
        ans = min(ans, ca);
        a++;
        // cout << a << endl;
    }
    return ans;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}