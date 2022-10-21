#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v(3);
        for (auto &val : v)
        {
            cin >> val;
        }
        sort(v.begin(), v.end());
        if (v[0] + v[1] == v[2])

        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}