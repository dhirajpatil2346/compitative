#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL a, b;
    cin >> a >> b;
    a = abs(a - b);
    LL c = 0;
    LL op = 0;
    for (LL i = 1;; i++, op++)
    {
        if ((c - a) >= 0 && (c - a) % 2 == 0)
        {
            cout << op << endl;
            return;
        }
        c += i;
    }
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