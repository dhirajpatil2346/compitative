#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int steps = k / (n - 1);
        // cout << steps << endl;
        int inc = k % (n - 1);
        // cout << inc << endl;
        int ans = steps * n + inc;
        if (ans % n == 0)
        {
            cout << ans - 1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}