#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        vector<char> even;
        /* code */

        int n;
        cin >> n;

        string s = to_string(n);
        if (n % 2 == 0)
        {
            cout << 0 << endl;
        }
        else if ((s.length() == 1) && (s[0] - 0) % 2 != 0)
            {
                cout << -1 << endl;
            }
        
        
        else if (n == n)
        {
            if ((s[0] - 0) % 2 != 0)
            {
                for (int i = 0; i < s.length(); i++)
                {
                    if (((s[i] - 0) % 2) == 0)
                    {
                        even.push_back(s[i]);
                    }
                }
                if (even.size() >= 0)
                {
                    cout << 2 << endl;
                }
            }
            else
            {
                for (int i = 0; i < s.length(); i++)
                {
                    if (((s[i] - 0) % 2) == 0)
                    {
                        even.push_back(s[i]);
                    }
                }
                if (even.size() > 0)
                {
                    cout << 1 << endl;
                }
            }
        }
        else
        {
            cout << -1 << endl;
        }
        /*

        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] - 0) % 2 != 0)
            {
                cout << -1 << endl;
                break;
            }
        }
        */
    }
    return 0;
}