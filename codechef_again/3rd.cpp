#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL cnt(LL x)
{
    LL op = 0;
    while (x)
    {
        if (x % 2ll == 0)
            return -1;
        x /= 2ll;
        op++;
    }
    return op;
}
bool isprime(LL n)
{
    if (n <= 1)
        return false;
    for (LL i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
void solve()
{
    LL h;
    cin >> h;
    if (isprime(h))
    {
        cout << 1 << endl;
        return;
    }
    LL c = 1, ans = cnt(h);
    LL op = 0;
    while (c <= h)
    {
        op++;
        if (isprime(h - c))
        {
            op++;
            if (ans == -1)
                ans = op;
            else
                ans = min(ans, op);
            // break;
        }
        c *= 2ll;
        c++;
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
/*
1010




*/