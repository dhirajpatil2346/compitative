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
        vector<int> v(n), op(n+1), nv(n);
        int p = 0;
        for (auto &val : v)
        {
            cin >> val;
            op[val] = p;
            p++;
        }
        nv = v;
        sort(nv.begin(), nv.end());
        if (n == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (i == op[nv[i]])
                {
                    int temp = nv[i];
                    nv[i] = nv[i + 1];
                    nv[i + 1] = temp;
                    i++;
                }
            }
            if (n - 1 == op[nv[n - 1]])
            {
                int temp = nv[n - 1];
                nv[n - 1] = nv[n - 2];
                nv[n - 2] = temp;
            }
            for (auto &val : nv)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}