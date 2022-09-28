#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, a, b, c;
        cin >> w >> a >> b >> c;
        if (w == a + b + c)
        {
            cout << "YES" << endl;
        }
        else if (w == a)
        {
            cout << "YES" << endl;
        }
        else if (w == b)
        {
            cout << "YES" << endl;
        }
        else if (w == c)
        {
            cout << "YES" << endl;
        }
        else if (w == a + b)
        {
            cout << "YES" << endl;
        }
        else if (w == a + c)
        {
            cout << "YES" << endl;
        }
        else if (w == c + b)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}