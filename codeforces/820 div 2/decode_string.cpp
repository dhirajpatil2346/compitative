#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (i < n - 3 && s[i + 3] == '0' && s[i + 2] == '0')
            {
                int f = s[i] - '0';
                //cout<<f<<endl;
                ans += char(f + 'a' - 1);
                f = s[i] - '0';
            }
            else if (i < n - 2 && s[i + 2] == '0')
            {
                int f = s[i] - '0';
                int sc = s[i + 1] - '0';
                int final = f * 10 + sc;
                //cout<<final<<endl;
                // //cout<<final<<endl;
                ans += char(final + 'a' - 1);
                i+=2;
            }
            else
            {
                int f = s[i] - '0';
                //cout<<f<<endl;
                ans += char(f + 'a' - 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
n = ch - a+1;
ch = n+ a - 1;
ch = a + (n-1);

p = ch - a + 1
ch = p + a - 1

*/