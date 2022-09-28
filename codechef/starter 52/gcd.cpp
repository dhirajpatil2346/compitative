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
        vector<int> v(n);
        for (auto &val : v)
        {
            //cout << val << " ";
        }
        //cout << endl;
        for (auto &val : v)
        {
            cin >> val;
        }
        sort(v.begin(), v.end());
        for (auto &val : v)
        {
            //cout << val << " ";
        }
        //cout << endl;
        vector<bool> vis(n);
        bool one = false;
        if (v[0] == 1)
        {
            one = true;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if(vis[j])
                {
                    continue;
                }
                if ((v[j] % v[i]) == 0)
                {
                    v[j] = v[i];
                    vis[j] = true;
                }
                else
                {
                    int k = __gcd(v[i], v[j]);
                    v[i] = k;
                    v[j] = k;
                    vis[j] = true;
                }
                if (v[i] == 1 || v[j] == 1)
                {
                    one = true;
                    break;
                }
            }
        }
        if (one)
        {
            cout << n << endl;
        }
        else
        {
            for (auto &val : v)
            {
                //cout << val << " ";
            }
            //cout << endl;
            long long sum = 0;
            for (auto &val : v)
            {
                sum += val;
            }
            cout << sum << endl;
        }
    }
    return 0;
}