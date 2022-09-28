#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b > c)
        {
            int req = b - c;
            cout << req / c + c - 1 << endl;
        }
        else if (b == c)
        {
            cout << c - 1 << endl;
            
        }
    }
    return 0;
}