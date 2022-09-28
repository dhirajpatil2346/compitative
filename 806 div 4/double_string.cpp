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
        vector<string> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        map<string, bool> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                string k = "";
                k += v[i];
                k += v[j];
                m[k] = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (m[v[i]])
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}