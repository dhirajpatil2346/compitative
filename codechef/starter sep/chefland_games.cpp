#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int usm = 0;
        int j = 4;
        while (j--)
        {
            int x;
            cin >> x;
            usm += x;
        }
        if (usm == 0)
        {
            cout << "IN" << endl;
        }
        else
        {
            cout << "OUT" << endl;
        }
    }
    return 0;
}