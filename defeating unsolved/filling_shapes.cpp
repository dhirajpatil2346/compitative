#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    // {

    // }
    LL n;
    cin >> n;
    cout << ((n & 1) ? 0 : (1ll << (n / 2))) << endl;
    return 0;
}