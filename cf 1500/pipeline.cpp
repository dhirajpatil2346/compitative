#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    if (n == k)
    {
        cout << 1 << endl;
        return;
    }
    if (n < k)
    {
        cout << -1 << endl;
        return;
    }
    if (n % k == 1)
        cout << 1 << endl;
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
    }
    return 0;
}