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
    char last = s[0];
    string ans = "";
    ans += last;
    int i = 1;
    for (int i = 1; i < n;)
    {
        if (s[i] != last)
        {
            i++;
        }
        else
        {
            i++;
            if (i >= n)
                break;
            last = s[i];
            ans += s[i];
            i++;
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