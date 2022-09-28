#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v(3);
        for (auto &val : v)
        {
            cin >> val;
        }
        sort(v.rbegin(), v.rend());
        int cntz = 0;
        for (auto &val : v)
        {
            if (val <= 1)
            {
                cntz++;
            }
        }
        // if (cntz <= 2)
        // {
        //     int z = 0;
        //     for (auto &val : v)
        //     {
        //         if (val == 0)
        //         {
        //             z++;
        //         }
        //     }
        //     cout << 3 - z << endl;
        // }
        // else
        // {
            int can_do = 0;
            if (v[0] > 1 && v[1] > 1)
            {
                can_do++;
                v[0]--;
                v[1]--;
            }
            if (v[0] > 1 && v[2] > 1)
            {
                can_do++;
                v[0]--;
                v[2]--;
            }
            if (v[1] > 1 && v[2] > 1)
            {
                can_do++;
                v[1]--;
                v[2]--;
            }
            int h = 0;
            for(auto &val:v)
            {
                if(val>0)
                {
                    h++;
                }
            }
            cout << h + can_do << endl;
        // }
    }

    return 0;
}