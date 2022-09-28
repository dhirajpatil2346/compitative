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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int key = v[0];
        if (v[0] != v[1] && v[0] == v[2])
        {
            cout << 2 << endl;
        }
        else if (v[1] == v[2] && v[0] != v[1])
        {
            cout << 1 << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] != key)
                {
                    cout << i + 1 << endl;
                }
            }
        }
    }
    return 0;
}