#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        for (int i = 0; i < c; i++)
        {
            int x, y;
            cin >> x >> y;
            for (int j = x - 1; j < y; j++)
            {
                s += s[j];
            }
        }
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            cout << s[x - 1] << endl;
        }
    }
    return 0;
}