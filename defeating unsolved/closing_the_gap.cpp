#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    LL ac = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        ac += c;
    }
    cout << ((ac % n) != 0) << endl;
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