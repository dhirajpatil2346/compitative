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
        vector<int> v, v1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
            v1.push_back(x);
        }
        sort(v1.begin(), v1.end());
        int m1 = v1[n - 1], m2 = v1[n - 2];
        // cout << m1 << "     " << m2 << endl;
        int p1, p2;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] == m1)
            {
                p1 = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] == m2)
            {
                p2 = i;
                break;
            }
        }
        // cout << p1 << "     " << p2 << endl;
        if (p1 == n - 1)
        {
            cout << 0 << endl;
        }
        else
        {
            if (p1 > p2)
            {
                // big=p1;
                cout << (n - 1 - p1) << endl;
            }
            else
            {
                cout << (n - p2) << endl;
            }
            // cout<<n-1-big<<endl;
        }
    }
    return 0;
}