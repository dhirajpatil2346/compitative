#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a1, b;
        cin >> a1 >> b;
        set<char> a;
        a.insert(a1[0]);
        a.insert(a1[1]);
        a.insert(b[0]);
        a.insert(b[1]);
        if (a.size() == 1)
        {
            cout << 0 << endl;
        }
        else if (a.size() == 2)
        {
            cout << 1 << endl;
        }
        else if (a.size() == 3)
        {
            cout << 2 << endl;
        }
        else if (a.size() == 4)
        {
            cout << 3 << endl;
        }
    }
    return 0;
}