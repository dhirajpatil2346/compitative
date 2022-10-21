/*
6
1 6 2 5 3 4
5
1 5 2 4 3
*/
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
        int f = 1, l = n;
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                cout << l-- << " ";
            }
            else
            {
                cout << f++ << " ";
            }
        }
        cout << endl;
    }
    return 0;
}