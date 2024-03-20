#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int x = 0;
    while (n--)
    {
        int a;
        cin >> a;
        x ^= a;
    }
    if (x == 0)
        cout << "Joe" << endl;
    else
        cout << "Mike" << endl;
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