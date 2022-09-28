#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, big, small;
        cin >> a >> b;
        if (a > b)
        {
            big = a;
            small = b;
        }
        else
        {
            big = b;
            small = a;
        }
        int get = big - small;
        if (get % 10 == 0)
        {
            cout << get / 10 << endl;
        }
        else
        {
            cout << get / 10 + 1 << endl;
        }
    }
    return 0;
}