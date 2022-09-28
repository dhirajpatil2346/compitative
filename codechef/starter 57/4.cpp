#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int one = 0, zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                zero++;
            }
            else
            {
                one++;
            }
        }
        int zp = -1, zpg = -1;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
            {
                zp = i;
            }
        }
        // cout << zp << endl;
        if (zp != -1)
        {
            for (int i = zp + 1; i < n; i++)
            {
                if (s[i] == '1')
                {
                    zpg = i;
                    break;
                }
            }
        }
        // cout << zpg << endl;
        if (zpg == -1)
        {
            cout << s << endl;
        }
        else
        {
            string ans = "";
            while (zero--)
            {
                ans += '0';
            }
            while (one--)
            {
                ans += '1';
            }
            cout << ans << endl;
        }
    }
    return 0;
}