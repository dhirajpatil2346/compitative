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
        bool lrev = false;
        bool move = true; // true if alice has to move else false for bob
        int a = 0, b = 0;
        if (n % 2)
        {
            if (s[n / 2] == '0')
            {
                a++;
                z--;
                move = !move;
            }
        }
        while (z)
        {
            if(z%2)
            {
                
            }
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