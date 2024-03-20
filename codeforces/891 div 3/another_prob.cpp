#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    LL fans = 0;
    for (int i = 0; i <= n; i++)
    {
        LL maxi = 0, cans = 0;
        // till i
        for (LL j = 1; j <= i; j++)
        {
            cans += j * j;
            maxi = max(maxi, j * j);
        }
        // from n
        for (LL j = i+1, k = n; j <= n; j++, k--)
        {
            cans += j * k;
            maxi = max(maxi, j * k);
        }
        cans -= maxi;
        fans = max(fans, cans);
    }
    cout << fans << endl;
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