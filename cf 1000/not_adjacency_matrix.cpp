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
        if (n == 2)
        {
            cout << -1 << endl;
        }
        else if (n == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            vector<int> v;
            for (int i = 1; i <= n * n; i += 2)
            {
                v.push_back(i);
            }
            for (int i = 2; i <= n * n; i += 2)
            {
                v.push_back(i);
            }
            int pos = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << v[pos] << " ";
                    pos++;
                }
                cout << endl;
            }
        }
    }
    return 0;
}