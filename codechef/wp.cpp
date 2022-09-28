#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int n;
    cin >> n;
    for (unsigned int a = 0; a < n; a++)
    {
        unsigned int x;
        cin >> x;
        string s;
        cin >> s;
        unsigned int j = 0;
        for (unsigned int i = 0; i < s.length();)
        {
            if (s[i] == '0')
            {
                while ((i < s.length() && (s[i] == '0')))
                {
                    i++;
                }
            }
            else
            {
                while ((i < s.length() && (s[i] == '1'))){
                    i++;
                }
            }
            j++;
        }
        if (j % 2 == 0)
        {
            cout << "RAMADHIR" << endl;
        }
        else
        {
            cout << "SAHID" << endl;
        }
    }
    return 0;
}