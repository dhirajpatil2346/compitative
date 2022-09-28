#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    bool fault = false;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() == 0)
        {
            continue;
        }
        int c = 0;
        for (auto &child : v[i])
        {
            if (v[child].size() == 0)
            {
                c++;
            }
        }
        if (c < 3)
        {
            fault = true;
        }
    }
    if (fault)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}