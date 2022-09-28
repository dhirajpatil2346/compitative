#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        map<int, int> m;
        int p = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> v1 = v;
        sort(v1.begin(), v1.end());
        for (int i = 0; i < n; i++)
        {
            m[v1[i]] = i;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (m[v[i]] == ((m[v[i + 1]]) - 1))
            {
                continue;
            }
            else
            {
                // cout << v[i] << endl;
                p++;
            }
        }
        // cout << p << endl;
        if (p > k)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}