#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool got = false;
        string n = "";
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (got)
            {
                break;
            }
            int f = s[i] - '0', sc = s[i + 1] - '0';
            int newn = f + sc;
            if (newn >= 10)
            {
                got = true;
                for (int k = 0; k < i; k++)
                {
                    n += s[k];
                }
                n += to_string(newn);
                for (int k = i + 2; k < s.length(); k++)
                {
                    n += s[k];
                }
                break;
            }
        }
        if (got)
        {
            cout << n << endl;
        }
        else
        {
             int f = s[0] - '0', sc = s[1] - '0';
            int newn = f + sc;
            n += to_string(newn);
            for (int i = 2; i < s.length(); i++)
            {
                n += s[i];
            }
            cout << n << endl;
        }
    }
    return 0;
}