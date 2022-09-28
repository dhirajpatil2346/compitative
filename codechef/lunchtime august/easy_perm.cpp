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
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            vector<int> v(n);
            v[0] = 2, v[1] = 1;
            int start = 3;
            for (int i = 2; i < n; i++)
            {
                v[i] = start;
                start++;
            }
            for (auto &val : v)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}