#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int a, b;
    cin >> a >> b;
    // if bits are not matching put them 0
    // now consider only part of not matching
    // 0101
    // 1010
    // consider 1st mismatched
    // if b has than then from next for a make 1 for every a's zero make 0 for every one's make 0
    // ans 0010
    // 0101
    // 1010
    /*
    0010 ^ 0101 = 0111 = 7
    0010 ^ 1010 = 1100 = 12 => 5
    */
    if (a > b)
        swap(a, b);
    // now b has 1st missmatched bit
    int ans = 0;
    int startbit = 0;
    for (int i = 29; i >= 0; i--)
    {
        if (((1 << i) & a) && ((1 << i) & b))
            continue;
        if ((!((1 << i) & a)) && (!((1 << i) & b)))
            continue;
        startbit = i;
        break;
    }
    startbit--;
    for (; startbit >= 0; startbit--)
        if ((a & (1 << startbit)))
            continue;
        else
            ans |= (1 << startbit);
    // cout << abs((ans ^ a) - (ans ^ b)) << endl;
    cout << ans << endl;
    // cout << endl;
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