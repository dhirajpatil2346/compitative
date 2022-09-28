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
        string s = to_string(n);
        int len = s.length();
        bool got = true;
        if (n % 2 == 0)
        {
            cout << 0 << endl;
        }
        else if (len == 1 && n % 2 != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0, j = 1; i < len; j++, i--)
            {
                int k = s[i] - '0';
                cout<<s[i]<<"    "<<k<<endl;
                if (i == len - 1)
                {
                    if ((k) % 2 == 0)
                    {
                        cout << j << endl;
                        got = false;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                if ((k) % 2 == 0)
                {
                    cout << j << endl;
                    got = false;
                    break;
                }
            }
            if (got)
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}