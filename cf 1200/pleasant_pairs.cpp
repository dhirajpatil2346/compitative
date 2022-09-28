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
        for (auto &val : v)
        {
            cin >> val;
        }
        long long c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // cout <<v[i]<<"  "<<v[j]<<"  "<< v[i] * 1ll * v[j] << " " << (2 + i + j) << endl;
                if (v[i] * 1ll * v[j] == (2 + i + j))
                {
                cout <<v[i]<<"  "<<v[j]<<"  "<< v[i] * 1ll * v[j] << " " << (2 + i + j) << endl;

                    c++;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}