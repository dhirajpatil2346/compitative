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
        vector<int> v(n);
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            int k = i;
            if (k % 2 == 1 && ((v[i] % 2) != (k % 2)))
            {
                odd++;
            }
            else if (k % 2 == 0 && ((v[i] % 2) != (k % 2)))
            {
                even++;
            }
        }
        if (odd != even)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << odd << endl;
        }
    }
    return 0;
}