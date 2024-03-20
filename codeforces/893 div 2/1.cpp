#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL a, b, c;
    cin >> a >> b >> c;
    LL two = 2;
    a += (c / two + c % two);
    b += (c / two);
    if (a > b)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
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