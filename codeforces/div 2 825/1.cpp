#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n), v1(n);
        int s1 = 0, s2 = 0;
        for (auto &val : v)
        {
            cin >> val;
            s1 += val;
        }
        for (auto &val : v1)
        {
            cin >> val;
            s2 += val;
        }
        if (v == v1)
        {
            cout << 0 << endl;
        }
        else if (s1 == s2)
        {
            cout << 1 << endl;
        }
        else
        {
            vector<int> n1 = v, n2 = v1;
            if (s1 > s2)
            {
                // cout << "here" << endl;
                int i = 0;
                int op = 0;
                while (i < n && s1 > s2)
                {
                    if (v[i] == v1[i])
                    {
                        i++;
                        continue;
                    }
                    else if (v[i] == 0)
                    {
                        i++;
                        continue;
                    }
                    else
                    {
                        // cout << i << endl;
                        v[i]--;
                        i++;
                        s1--;
                        op++;
                    }
                }
                if (v == v1)
                {
                    cout << op << endl;
                }
                else
                {
                    cout << op + 1 << endl;
                }
            }
            else
            {
                int i = 0;
                int op = 0;
                while (i < n && s1 < s2)
                {
                    if (v[i] == v1[i])
                    {
                        i++;
                        continue;
                    }
                    else if (v1[i] == 0)
                    {
                        i++;
                        continue;
                    }
                    else
                    {
                        v1[i]--;
                        i++;
                        s2--;
                        op++;
                    }
                }
                if (v == v1)
                {
                    cout << op << endl;
                }
                else
                {
                    cout << op + 1 << endl;
                }
            }
        }
    }
    return 0;
}