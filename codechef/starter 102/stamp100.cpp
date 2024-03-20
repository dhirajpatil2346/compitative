#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos = n;
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == '1')
        {
            pos = i;
            break;
        }
    }
    for (int i = pos + 1; i < n; i++)
        s[i] = '0';
    cout << s << endl;
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