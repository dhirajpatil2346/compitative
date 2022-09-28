#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
        bool j = m.count(x);
        if (!j)
        {
            m.insert(make_pair(x, 1));
        }
        else
        {
            m[x]++;
        }
    }

    int sum = accumulate(v.begin(), v.end(), 0);
    sum /= 100;
    if (sum % 2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (m.size() > 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second % 2 == 0)
            {
                it->second = 0;
            }
            else
            {
                it->second = 1;
            }
        }
        sum = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            int y = it->second;
            if (y == 1)
            {
                sum++;
            }
        }
        if (sum % 2 == 0)
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