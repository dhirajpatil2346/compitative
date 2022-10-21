#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for (auto &val : v)
    {
        cin >> val;
        m[val]++;
    }
    if (m.size() < 6)
    {
        cout << n << endl;
    }
    else
    {
        for (auto &val : m)
        {
            cout << val.first << " " << val.second << endl;
        }
        int mini = INT_MAX;
        for (auto &val : m)
        {
            mini = min(mini, val.second);
        }
        int total = mini * 6;
        cout << n - total << endl;
    }
    return 0;
}