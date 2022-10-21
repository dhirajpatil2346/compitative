/*
0 1 0 ..  1 0 ..  0 1
0 1 ..  0 1 .. 1 1 .. 0 1 0..
*/

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
        vector<int> v(n);
        vector<bool> vis(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        int i = 0;
        int sc = 0;
        while (i < n)
        {
            int c = 0;
            if (v[i] == 0)
            {
                i++;
                while (i < n)
                {
                    if (v[i] == 1)
                    {
                        vis[i] = true;
                        vis[i - 1] = true;
                        i++;
                        sc++;
                        break;
                    }
                    i++;
                }
            }
            else
            {
                i++;
                if (i == n)
                {
                    break;
                }
                else if (v[i] == 0)
                {
                    sc++;
                    continue;
                }
                else
                {
                    i++;
                    continue;
                }
            }
        }
        cout << sc << endl;
    }
    return 0;
}