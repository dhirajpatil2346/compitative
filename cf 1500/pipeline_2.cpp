#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

void sol(LL n, LL k)
{
    n--;
    LL l = 0, r = k - 1;
    LL a = -1;
    while (l <= r)
    {
        LL m = (l + r) / 2;
        LL ele = k - 1 - m + 1;
        LL tre = (ele * (m + k - 1)) / 2;
        if (tre >= n)
        {
            a = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    if (a == -1)
        cout << -1 << endl;
    else
        cout << k - 1 - a + 1 << endl;
}

void solve()
{
    LL n, k;
    cin >> n >> k;
    if (n == 1)
        cout << 0 << endl;
    else if (k > n)
        cout << -1 << endl;
    else if (k == n)
        cout << 1 << endl;
    else
        sol(n, k);
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