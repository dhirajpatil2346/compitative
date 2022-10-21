#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
        bool got = false;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1')
            {
                cout << i << endl;
                got = true;
                break;
            }
        }
        if (!got)
        {
            cout << n << endl;
        }
    }
    return 0;
}