#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 1001;
        set<pair<int, int>> m;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (__gcd(i, j) == 1)
                {
                    m.insert({i, j});
                }
            }
        }
        map<int, int> pos;
        int x;
        cin >> x;
        x++;
        for (int i = 1; i < x; i++)
        {
            int k;
            cin >> k;
            pos[k] = i;
        }
        int maxi = -1;
        for (auto &val : m)
        {
            int i = val.first, j = val.second;
            if (pos[i] == 0 || pos[j] == 0)
            {
                continue;
            }
            else
            {
                maxi = max(maxi, pos[i] + pos[j]);
            }
        }

        cout << maxi << endl;
    }
    return 0;
}