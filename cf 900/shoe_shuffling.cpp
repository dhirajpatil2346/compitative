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
        vector<int> v(n), p(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        for (int i = 0; i < n; i++)
        {
            int key = v[i];
            for (int j = i + 1; j < n; j++)
            {
                if (key == v[j])
                {
                    if (p[i] == 0 && p[j] == 0)
                    {
                        p[i] = j + 1;
                        p[j] = i + 1;
                    }
                    else
                    {
                        int temp = p[i];
                        p[j] = p[i];
                        p[i] = j + 1;
                    }
                    break;
                }
            }
        }
        bool got = false;
        for (auto &val : p)
        {
            if (val == 0)
            {
                got = true;
                break;
            }
        }
        if (got)
        {
            cout << -1;
        }
        else
        {
            for (auto &val : p)
            {
                cout << val << " ";
            }
        }
        cout << endl;
    }
    return 0;
}