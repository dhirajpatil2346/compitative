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
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            m[x]++;
        }
        int maxi = INT_MIN;
        for (auto &val : m)
        {
            maxi = max(maxi, val.second);
        }
        cout << n - maxi << endl;
    }
    return 0;
}