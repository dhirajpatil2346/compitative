#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;
    for (int x = 0; x < m; x++)
    {
        int n;
        cin >> n;
        for (int i = 1, k = 2; i <= n;)
        {
            i += k;
            if (n % i == 0)
            {
                cout << n / i << endl;
                break;
            }
            k = k * 2;
        }
    }
    return 0;
}