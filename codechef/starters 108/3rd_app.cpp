#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (s.length() == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if (abs(count(s.begin(), s.end(), '0') - count(s.begin(), s.end(), '1')) >= 2)
    {
        cout << "NO" << endl;
        return;
    }
    if (s[n - 1] == s[n - 2])
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
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