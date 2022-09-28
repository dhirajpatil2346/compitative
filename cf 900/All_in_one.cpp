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
        int sum = accumulate(v.begin(), v.end(), 0);
        if (sum % n)
        {
            cout << "NO" << endl;
        }
        else
        {
            bool got = true;
            int r = sum / n;
            for (auto &val : v)
            {
                if (val == r)
                {
                    got = false;
                    break;
                }
            }
            if (got)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}