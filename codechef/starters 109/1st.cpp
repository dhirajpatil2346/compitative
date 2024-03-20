#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL solve()
{
    LL a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    LL l = 0, r = 1e7;
    LL ans = 0;
    while (l <= r)
    {
        // a is small
        // cout << l << " " << r << endl;
        LL mid = (l + r) / 2ll;
        if ((a + b) % 2ll == 1ll)
        {
            // mid * 2 add
            if ((a + (mid * 2)) < b)
            {
                ans = a + b + (mid * 2);
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        else
        {
            // mid * 2 + 1
            LL to_add = mid * 2 + 1;
            if ((a + to_add) < b)
            {
                ans = a + b + to_add;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return ans;
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
        cout << solve() << endl;
    }
    return 0;
}