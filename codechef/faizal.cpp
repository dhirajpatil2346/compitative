#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    for (int x = 0; x < n; x++)
    {

        long long int m;
        cin >> m;
        int v[m];
        for (long long int i = 0, j = 0; i <= m;)
        {
            v[i] = j;
            j += 2;
            i = i + 2;
        }
        for (long long int p = 1, q = 3; p <= m;)
        {
            v[p] = q;
            q += 2;
            p = p + 2;
        }
        cout << v[m] << endl;
    }
    return 0;
}