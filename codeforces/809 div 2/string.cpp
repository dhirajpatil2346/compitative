#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        string s = "";
        for (int i = 0; i < m; i++)
        {
            s += 'B';
        }
        for (int i = 0; i < n; i++)
        {
            int k1 = v[i] - 1;
            int k2 = m - v[i];
            if (k1 < k2 && s[k1] != 'A')
            {
                s[k1] = 'A';
            }
            else if (k2 < k1 && s[k2] != 'A')
            {
                s[k2] = 'A';
            }
            else if (s[k1] == 'A')
            {
                s[k2] = 'A';
            }
            else
            {
                s[k1] = 'A';
            }
        }

        cout << s << endl;
    }
    return 0;
}