#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<LL> op;
    for (auto &val : v)
    {
        LL x = 0;
        if (val % (a + b) == 0)
        {
            x = a + b;
        }
        else
        {
            x = val % (a + b);
        }
        LL o = x / a + min(1ll, x % a);
        o--;
        op.push_back(o);
    }
    sort(op.begin(), op.end());
    int r = 0;
    LL curr = 0;
    for (auto &val : op)
    {
        if ((val + curr) > k)
            break;
        r++;
        curr += val;
    }
    cout << r << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}