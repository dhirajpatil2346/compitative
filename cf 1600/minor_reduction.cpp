#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string s;
    cin >> s;
    // cout << s << endl;
    for (int i = s.length() - 2; i >= 0; i--)
    {
        string h = s.substr(i, 2);
        int num = h[0] - '0' + h[1] - '0';
        h = to_string(num);
        if (h.length() > 1)
        {
            for (int j = 0; j < i; j++)
                cout << s[j];
            cout << h;
            for (int j = i + 2; j < s.length(); j++)
                cout << s[j];
            cout << endl;
            return;
        }
    }
    for (int i = 0; i < s.length() - 1; i++)
    {
        string h = s.substr(i, 2);
        int num = h[0] - '0' + h[1] - '0';
        h = to_string(num);
        if (h[0] == '0')
            continue;
        if (h[0] >= s[0])
        {
            for (int j = 0; j < i; j++)
                cout << s[j];
            cout << h;
            for (int j = i + 2; j < s.length(); j++)
                cout << s[j];
            cout << endl;
            return;
        }
    }
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}