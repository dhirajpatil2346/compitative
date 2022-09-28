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
        vector<unordered_set<int>> v[6];
        map<int, vector<int>> m;
        bool got = false;
        for (int i = 0; i < n; i++)
        {
            int z;
            cin >> z;
            unordered_set<int> us;
            while (z--)
            {
                int k;
                cin >> k;
                us.insert(k);
            }
            v[us.size()].push_back(us);
            if (v[5].size())
            {
                got = true;
            }
        }
        if (m[5].size())
        {
            got = true;
        }
        for (int i = 1; i <= 5; i++)
        {
            // int r = 5 - i;
            cout<<i<<" "<<r<<endl;
            for (int j = 0; j < v[i].size(); j++)
            {
                cout << i << " " << j << endl;
                unordered_set<int> us1 = v[i][j];
                for (int k = 0; k < v[r].size(); k++)
                {
                    unordered_set<int> us2 = v[r][k];
                    unordered_set<int> test;
                    for (auto &val : us1)
                    {
                        test.insert(val);
                    }
                    for (auto &val : us2)
                    {
                        test.insert(val);
                    }
                    cout << test.size() << endl;
                    if (test.size() == 5)
                    {
                        got = true;
                    }
                }
            }
        }

        if (got)
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
