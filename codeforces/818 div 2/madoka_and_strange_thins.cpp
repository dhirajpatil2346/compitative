#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // int k = gcd(i, j);
                // cout << k << " ";
                // lcm = i*j/gcd(i,j)
                int g = gcd(i, j);
                int l = (i * j) / g;
                if (l / g <= 3)
                {
                    cout << i << " " <<j << endl;
                    c++;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}