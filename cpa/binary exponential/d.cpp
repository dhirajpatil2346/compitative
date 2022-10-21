#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int zero = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zero = i;
            break;
        }
    }
    int len = n - zero;
    for (int i = n; i < 0; i++)
    {
        /* code */
    }
    
    return 0;
}