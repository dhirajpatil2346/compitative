#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string s;
    cin >> s;
    int one = count(s.begin(), s.end(), '1'), zero = count(s.begin(), s.end(), '0');
    if (one != zero)
    {
        cout << min(zero, one) << endl;
        return;
    }
    one = 0, zero = 0;
    int o = 0, z = 0;
    for (int i = 1; i < s.length(); i++)
        if (s[i] == '1')
            o++;
        else
            z++;
    for (int i = 0; i < s.length() - 1; i++)
        if (s[i] == '0')
            zero++;
        else
            one++;
    cout << max(min(o, z), min(zero, one)) << endl;
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