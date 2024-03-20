#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
string solve()
{
    LL a, b, n;
    cin >> a >> b >> n;
    string s = to_string(a);
    a *= 10ll;
    n--;
    LL r = a % b;
    if (r == 0)
        s.push_back('0');
    else if ((b - r) < 10)
        s.push_back(char(b - r + '0'));
    else
        return "-1";
    a = 0;
    // cout << s << endl;
    while (n--)
    {
        r = a % b;
        if (r == 0)
            s.push_back('0');
        else if ((b - r) < 10)
            s.push_back(char(b - r + '0'));
        else
            return "-1";
    }
    return s;
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
        cout << solve() << endl;
    }
    return 0;
}