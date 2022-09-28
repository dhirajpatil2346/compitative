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
        vector<unordered_set<int>> v;
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
            v.push_back(us);
        }
        bool got = false;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> us1 = v[i];
            if (v[i].size() == 5)
            {
                got = true;
            }
            if (got)
            {
                break;
            }
            for (int j = i + 1; j < n; j++)
            {
                unordered_set<int> us2 = v[j];
                unordered_set<int> us3 = us1;
                for (auto &val : us2)
                {
                    us3.insert(val);
                }
                if (us3.size() == 5)
                {
                    got = true;
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