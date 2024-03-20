#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    LL mn = b % a;
    {
        LL A = a, B = b;
        while (A && B)
        {
            // cout << A << " " << B << endl;
            if (A < B)
                swap(A, B);
            // now B is less than A
            if (A % B)
                mn = min(mn, A % B);
            A = A % B;
        }
    }
    // cout << mn << endl;
    if (mn == 0)
        mn = a;
    if ((c - 1) * a + mn < b)
        cout << "REBEL" << endl;
    else
        cout << "OBEY" << endl;
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