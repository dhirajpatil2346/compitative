#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        string y = "";
        int c0 = 0;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '0')
            {
                c0++;
            }
            else
            {
                y += s[i];
            }
        }

        for (int i = 0; i < m; i++)
        {
            string a = "";
            string b = "";
            len = y.length();
            for (int i = 0; i < len; i++)
            {
                if (y[i] == '0')
                {
                    c0++;
                }
                else
                {
                    b += y[i];
                }
            }
            int len = b.length();
            for (int i = 0; i < len; i++)
            {
                int l = b[i] - '0';
                l *= k;
                a += to_string(l);
            }
            y = a;
            a = "";
        }
        cout << y.length() + c0 << endl;
    }
    return 0;
}