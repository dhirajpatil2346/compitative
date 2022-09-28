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
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        int c = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = v[i] - i; j < n + 1; j += v[i])
            {
                // cout<<i<<endl;
                if ((j <= 0) || (j == i))
                {
                    continue;
                }
                long long k = v[i] * v[j];
                if ((i + j) == k)
                {
                    c++;
                }
            }
        }
        cout << c / 2 << endl;
    }
    return 0;
}