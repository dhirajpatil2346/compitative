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
        map<int, int> m;
        vector<int> v(n);
        for (auto &val : v)
        {
            cin >> val;
            m[val]++;
        }
        int maxi = INT_MIN;
        for (auto &val : m)
        {
            maxi = max(val.second, maxi);
        }
        if (n % 2)
        {
            int maxm = n / 2 + 1;
            if (maxi > maxm)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
        else
        {
            int maxm = n / 2;
            if (maxi > maxm)
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