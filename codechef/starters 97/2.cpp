// 10002100210021002100
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    // k zeroes are allowed
    // n = 15, k = 3
    // 100021000210002
    // first k + 1 has sum = 1
    // next (n - (k+1)) / (k+2) has sum 3 mult
    // left if greater than or equal to 2 then 3 else 2 for 1 and 0 for no
    LL sum = 1;
    n -= (k + 1);
    if (n > 0)
    {
        LL terms = (n - (k + 1)) / (k + 2);
        sum += terms * 3;
        n -= terms * (k + 2);
        if (n >= 2)
            sum += 3;
        else if (n >= 1)
            sum += 2;
    }
    cout << sum << endl;
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