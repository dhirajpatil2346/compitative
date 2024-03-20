#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool check(LL a, LL b, LL &x)
{
    if (a < b)
        swap(a, b);
    if (b == 0 && (a != x))
        return false;
    if (((a - x) % b) == 0)
        return true;
    return false;
}
bool g(LL a, LL b, LL &x)
{
    // if (a < b)
    //     swap(a, b);
    // // a - cb = x
    // // a - x = cb
    // // (a-x) % b should be 0
    // // if mod is zero then we have got answer
    // // else
    // // a = a%b , b = b
    // // swap a,b
    // // return g(a,b,x)
    if (x > max(a, b))
        return false;
    if (a == x || b == x)
        return true;
    if (a == b)
        return a == x;
    if (b == 0 && (a != x))
        return false;
    if ((a - x) % b)
    {
        return (g(b, a % b, x) | check(abs(a - b), a, x));
    }
    return true;
    // return (((x % __gcd(a, b)) == 0) && (x <= a || x <= b));
}
void solve()
{
    LL a, b, x;
    cin >> a >> b >> x;
    if (a < b)
        swap(a, b);
    if (g(a, b, x))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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