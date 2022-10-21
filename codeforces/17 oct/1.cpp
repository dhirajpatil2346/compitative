#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int req = 10 - n - 1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
        }

        /*

10 - i - 1  * 6
 8 9 6
 8 0 6
        */
        int sum = 0;
        while (req != 0)
        {
            sum += (6 * req);
            req--;
        }
        cout << sum << endl;
    }
    return 0;
}