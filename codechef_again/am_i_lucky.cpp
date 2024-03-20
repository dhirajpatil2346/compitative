#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL total, boys, k, a = 1e11, b = 1e11, c = 1e11;
    cin >> total >> boys >> k;
    LL girls = total - boys;
    {
        // take it normally
        a = abs((boys % k) - (girls % k));
    }
    {
        // add boys
        LL byz = boys % k, grz = girls % k;
        if ((boys / k) >= k)
            byz += k;
        b = abs((byz % k) - (grz % k));
    }
    {
        // add girls
        LL byz = boys % k, grz = girls % k;
        if ((girls / k) >= k)
            grz += k;
        c = abs((byz % k) - (grz % k));
    }
    cout << min({a, b, c}) << endl;
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