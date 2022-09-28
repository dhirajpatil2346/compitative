#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int cost = 0;
        string s;
        cin >> s;
        int n = s.length();
        int j = n - 1;
        if (s[j] == '1')
        {
            while (j >= 0 && s[j] == '1')
            {
                j--;
            }
        }
        else
        {
            while (j >= 0 && s[j] == '0')
            {
                j--;
            }
        }
        int i = 0;
        while (i < j)
        {
            if (s[i] == '1')
            {
                i++;
                continue;
            }
            if (s[j] == '0')
            {
                j--;
                continue;
            }
            if (i >= j)
            {
                continue;
            }
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            cost++;
        }
        cout << cost << endl;
    }
    return 0;
}