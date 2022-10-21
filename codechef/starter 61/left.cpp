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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> one, zero;
        int i = 0, sc = 0;
        while (i < n)
        {
            if (v[i] == 1)
            {
                one.push_back(i);
                if (one.size() && zero.size())
                {
                    vis[zero.back()] = true;
                    vis[one.back()] = true;
                    // cout << zero.back() << one.back() << endl;
                    sc++;
                    one.pop_back(), zero.pop_back();
                }
                i++;
            }
            else
            {
                zero.push_back(i);
                if (one.size() && zero.size())
                {
                    vis[zero.back()] = true;
                    vis[one.back()] = true;
                    // cout << zero.back() << one.back() << endl;
                    sc++;
                    one.pop_back(), zero.pop_back();
                }
                i++;
            }
        }
        i = 0;
        int curr = -1;
        while (i < n)
        {
            if (vis[i])
            {
                i++;
                continue;
            }
            else
            {
                // cout << i << endl;
                if (curr == -1)
                {
                    vis[i] = true;
                    curr = v[i++];
                    continue;
                }
                else
                {
                    curr = curr ^ v[i];
                    if (curr == 1)
                    {
                        sc++;
                        curr = -1;
                        vis[i] = true;
                        i++;
                        continue;
                    }
                    else
                    {
                        vis[i] = true;
                        i++;
                        continue;
                    }
                }
            }
        }
        cout << sc << endl;
    }
    return 0;
}