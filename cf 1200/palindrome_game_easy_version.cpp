#include <bits/stdc++.h>
using namespace std;

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
        int z = 0;
        for (auto &val : s)
        {
            if (val == '0')
            {
                z++;
            }
        }
        int a, b;
        if (z == 0)
        {
            a = 0, b = 0;
        }
        else if (z == 1)
        {
            a = 1, b = 0;
        }
        else if (z == 2)
        {
            a = 2, b = 0;
        }
        else if (z % 2)
        {
            a = 1, b = 2;
        }
        else
        {
            a = 2, b = 1;
        }
        if (a < b)
        {
            cout << "ALICE" << endl;
        }
        else if (a == b)
        {
            cout << "DRAW" << endl;
        }
        else
        {
            cout << "BOB" << endl;
        }
    }
    return 0;
}