#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int solve()
{
    int n;
    cin >> n;
    n--;
    int a, b;
    cin >> a >> b;
    bool fault = false;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (x >= a && y >= b)
            fault = true;
    }
    if (fault)
        return -1;
    // cout << a << " " << b << endl;
    return a;
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
        cout << solve() << endl;
    }
    return 0;
}