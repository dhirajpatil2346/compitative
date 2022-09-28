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
        vector<int> v(n), v1(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[i] = x;
            v1[i] = x;
        }
        sort(v1.begin(), v1.end());
        bool got = true;
        for (int i = 0; i < n; i++)
        {
            if (v1[i] != v[i])
            {
                cout << "YES" << endl;
                got = false;
                break;
            }
        }
        if (got)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}