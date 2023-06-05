#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    const LL mod = 1e9 + 7;
    LL n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << 1 << endl;
        return;
    }
    LL r = k;
    for(int i = 1 ; i < n / k ; i++)
        
        {
            r*=k;
            r%=mod;
        }
    for (int i = n/k; i < n; i++)
    {
        r *= (k - 1);
        r %= mod;
    }
    cout << r << endl;
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