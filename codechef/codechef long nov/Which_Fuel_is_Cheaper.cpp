#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        for (int j = 0; j < k; j++)
        {
            x += a;
            y += b;
        }
        // cout<<x<<endl<<y<<endl;
        if (x < y)
        {
            cout << "PETROL" << endl;
        }
        else if (x > y)
        {
            cout << "DIESEL" << endl;
        }
        else
        {
            cout << "SAME PRICE" << endl;
        }
    }

    return 0;
}