#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length(), j = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                s[i] = 'A';
                j++;
            }
            else if (i >= 2 && s[i - 2] == s[i])
            {
                s[i] = 'A';
                j++;
            }
        }
        cout << j << endl;
    }
    return 0;
}