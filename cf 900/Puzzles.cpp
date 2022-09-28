#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        v.push_back(y);
    }
    sort(v.begin(), v.end());
    if (n >= 4)
    {
        int req = v[3] - v[0];
        int ans = v[3] - v[0];
        for (int i = 0; i < v.size() - 3; i++)
        {
            req = v[i + 3] - v[i];
            if (req < ans)
            {
                ans = req;
            }
        }
        cout << ans;
    }
    else
    {
        cout << v[0] - v[v.size() - 1];
    }
    return 0;
}