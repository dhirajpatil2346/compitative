#include <bits/stdc++.h>
using namespace std;

int findsum(int n)
{
    if (n % 2 == 0)
    {
        return (n / 2) * (1 + n);
    }
    else
    {
        return (1 + n) / 2 * n;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> ans;
        for (auto &val : v)
        {
            cin >> val;
        }
        int i = 0;
        while (i < n)
        {
            if (v[i] == 0)
            {
                i++;
                continue;
            }
            int a = 0;
            while (i < n && v[i] == 1)
            {
                i++;
                a++;
            }
            ans.push_back(a);
        }
        int a = 0;
        for (auto &val : ans)
        {
            a += findsum(val);
        }
        cout << a << endl;
    }
    return 0;
}