#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL f(int a, int b, int x)
{
    return abs((a ^ x) - (b ^ x));
}
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    int ans = 0;
    int f = 0;
    int f1bit = 0, f2bit = 0;
    for (int i = 29; i >= 0; i--)
        if ((1 << i) & a)
        {
            f1bit = i;
            break;
        }
    for (int i = 29; i >= 0; i--)
        if ((1 << i) & b)
        {
            f2bit = i;
            break;
        }
    
    for (int i = 29; i >= 0; i--)
    {
        if (((1 << i) & a) && ((1 << i) & b))
            continue;
        if ((!((1 << i) & a)) && (!((1 << i) & b)))
            continue;
        if (f == 0)
        {
            ans |= (1 << i);
            f = abs(1 - f);
        }
        else
        {
            f = abs(1 - f);
        }
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
/*
1 => 001
2 => 010
x => 111
7^1 - 7^2 = 6 - 5 = 1


*/