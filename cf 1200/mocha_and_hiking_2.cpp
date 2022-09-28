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
        for (auto &val : v)
        {
            cin >> val;
        }
        // starting 1
        if (v[0] == 1)
        {
            cout << n + 1 << " ";
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        // ending 0
        else if (v[n - 1] == 0)
        {
            for (int i = 1; i <= n + 1; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        // find 0 1
        else
        {
            int p1 = 0, p2 = 1;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == 0 && v[i + 1] == 1)
                {
                    p1 = i, p2 = i + 1;
                    break;
                }
            }
            int k = 1;
            for (int i = 0; i <= p1; i++)
            {
                cout << k++ << " ";
            }
            cout << n + 1 << " ";
            for (int i = p1 + 1; i < n; i++)
            {
                cout << k++ << " ";
            }
            cout << endl;
        }
    }
    return 0;
}