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
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            m[x]++;
        }
        int more = 0, one = 0, maxi = INT_MIN;
        for (auto &val : m)
        {
            if (val.second == 1)
            {
                one++;
            }
            else
            {
                more++;
                maxi = max(maxi, val.second);
            }
        }
        // cout<<maxi<<"    "<<one<<endl;
        if (n == 1)
        {
            cout << 0 << endl;
        }
        else if (more == 0)
        {
            cout << 1 << endl;
        }
        else if (maxi <= one)
        {
            cout << maxi << endl;
        }
        else if (maxi - one >= 2)
        {
            cout << maxi - 1 << endl;
        }
        else
        {
            cout << min(maxi, one) << endl;
        }
    }
    return 0;
}