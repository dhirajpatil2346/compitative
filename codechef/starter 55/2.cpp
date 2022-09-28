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
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i]] = true;
        }
        int j;
        cin >> j;
        for (int i = 0; i < j; i++)
        {
            int x;
            cin >> x;
            m[x] = false;
        }
        for (int i = 0; i < n; i++)
        {
            if (m[v[i]])
            {
                cout << v[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}