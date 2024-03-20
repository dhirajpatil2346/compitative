#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int i = s1.length() - 1, j = s2.length() - 1;
    while (i >= 0 && j >= 0)
        if (s1[i] == s2[j])
            i--, j--;
        else
            i -= 2;
    if (j < 0)
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