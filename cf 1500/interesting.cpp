#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string a, b;
    cin >> a >> b;
    LL c = 0, ans = 0;
    int diff = b.length() - a.length();
    string j = "";
    while (diff--)
        j += "0";
    j += a;
    a = j;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        c *= 10;
        c += 1;
        LL inc = b[i] - a[i];
        ans += inc * c;
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