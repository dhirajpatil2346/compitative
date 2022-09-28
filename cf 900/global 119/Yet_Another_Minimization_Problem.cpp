#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = 2 * n;
    vector<int> a(n), b(n), c(k);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            c[i] = a[i];
        }
        for (int i = n, j = 0; i < k; i++, j++)
        {
            c[i] = b[j];
        }
        sort(c.begin(), c.end());
        for (int i = 0, j = 0; i < n; i += 2, j++)
        {
            a[j] = c[i];
        }
        for (int i = 1, j = 0; i < k; i += 2, j++)
        {
            b[j] = c[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<b[i]<<' ';
        }
        cout<<endl;
        long long z = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                z += pow(a[i] + b[i], 2);
            }
        }
        cout << z << endl;
    }
    return 0;
}