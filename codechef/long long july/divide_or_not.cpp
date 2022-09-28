#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        if (a % b == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            int start = 0;
            if (n <= a)
            {
                start = a;
            }
            else
            {
                start = n + a - (n % a);
            }
            int ans = 0;
            while (start % a != 0 && start % b == 0)
            {
                start += a;
            }
            cout << start << endl;
        }
    }
    return 0;
}