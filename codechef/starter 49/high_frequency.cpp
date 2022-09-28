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
        while (n--)
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
        int maxI = 0;
        for (auto &val : m)
        {
            if (val.second == maxi)
            {
                maxI = val.first;
            }
        }
        int g = 0;
        if (maxi % 2)
        {
            m[maxI] -= (maxi / 2 + 1);
            g = maxi / 2 + 1;
        }
        else
        {
            m[maxI] -= maxi / 2;
            g = maxi / 2;
        }
        for (auto &val : m)
        {
            g = max(g, val.second);
        }
        cout << g << endl;
    }
    return 0;
}