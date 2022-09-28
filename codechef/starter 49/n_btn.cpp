#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        string s, k;
        cin >> s >> k;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != k[i])
            {
                c++;
            }
        }
        if (c % 2 == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}