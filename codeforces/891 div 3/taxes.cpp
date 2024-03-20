#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

LL f(LL n)
{
    LL ret = 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            ret = i;
    }
    for (LL i = 2; i <= n - 2; i++)
    {
        ret = min(ret, f(i) + f(n - i));
    }
    return ret;
}
void solve()
{
    LL n;
    cin >> n;
    cout << f(n) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}