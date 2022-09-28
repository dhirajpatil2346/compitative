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
        vector<int> v1(n), v2(n);
        for (auto &val : v1)
        {
            cin >> val;
        }
        for (auto &val : v2)
        {
            cin >> val;
        }
        bool got = false;
        for (int i = 0; i < n; i++)
        {
            if (v2[i] > v1[i])
            {
                got = true;
                break;
            }
        }
        if (got)
        {
            cout << "NO" << endl;
        }
        else
        {
            unordered_set<int> us;
            int mz = 0;
            for (int i = 0; i < n; i++)
            {
                if (v2[i] == 0)
                {
                    mz = max(mz, v1[i] - v2[i]);
                }
                else
                {
                    us.insert(v1[i] - v2[i]);
                }
            }
            if(us.size()==0)
            {
                cout<<"YES"<<endl;
            }
            else if (us.size() > 1)
            {
                cout << "NO" << endl;
            }
            else if (*us.begin() < mz)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}