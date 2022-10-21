#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n ;
        cin>>n;
        string s;
        cin >> s;
        int op = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                op++;
            }
        }
        cout << op << endl;
    }
    return 0;
}