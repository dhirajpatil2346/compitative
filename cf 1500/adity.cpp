#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int solve(int a, int b)
{
    a = 3, b = 4;
    int c = 10;
    a = 10 + b;
    if ((b + c) < (c - b))
    {
        b = a + b + b;
        c += b;
    }
    a = 10 + b;
    return a + b + c;
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
        int a, b, c;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}