#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
        vector<int> op(n);
        int zero = 0, one = 0;
        for (auto &val : op)
        {
            cin >> val;
            if (val == 0)
            {
                zero++;
            }
            else
            {
                one++;
            }
        }
        vector<int> v1 = v;
        sort(v1.begin(), v1.end());
        if (v1 == v)
        {
            cout << "Yes" << endl;
        }
        else
        {
            if (one == n || zero == n)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}
