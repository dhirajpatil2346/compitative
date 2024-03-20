#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string s;
    string h = "0";
    cin >> s;
    string org = s;
    h += s;
    s = h;
    int pos = -1;
    for (int i = s.length() - 2; i >= 0; i--)
    {
        if (s[i + 1] >= '5')
        {
            pos = i;
            s[i + 1] = '0';
            int num = s[i] - '0' + 1;
            // cout << "--> " << i << " " << num << " " << s << endl;
            s[i] = char((num % 10) + '0');
            // cout << s[i] << endl;
            int carry = num / 10;
            for (int j = i - 1; j >= 0 && carry; j--)
            {
                num = s[j] - '0';
                num += carry;
                s[j] = char(num % 10 + '0');
                carry = num / 10;
            }
        }
        // cout << i << " " << h << endl;
    }
    int i = 0;
    if (pos != -1)
    {
        for (int j = pos + 1; j < s.length(); j++)
            s[j] = '0';
    }
    while (i < s.length() && s[i] == '0')
        i++;
    for (; i < s.length(); i++)
        cout << s[i];
    cout << endl;
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