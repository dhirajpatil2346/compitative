#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> v1(n), v2(m);
        for (auto &val : v1)
        {
            cin >> val;
        }
        for (auto &val : v2)
        {
            cin >> val;
        }
        vector<int> ans;
        bool fault = false;
        int i = 0, j = 0; // i for v1 and j for v2
        while (i < n && j < m)
        {
            if (fault)
            {
                break;
            }
            else if (v1[i] == 0)
            {
                i++;
                ans.push_back(0);
                k++;
            }
            else if (v2[j] == 0)
            {
                j++;
                ans.push_back(0);
                k++;
            }
            else
            {
                if (v1[i] <= v2[j])
                {
                    if (v1[i] <= k)
                    {
                        ans.push_back(v1[i]);
                        i++;
                    }
                    else
                    {
                        fault = true;
                    }
                }
                else
                {
                    if (v2[j] <= k)
                    {
                        ans.push_back(v2[j]);
                        j++;
                    }
                    else
                    {
                        fault = true;
                    }
                }
            }
        }
        // cout<<"exited"<<endl;
        while (i < n)
        {
            if (v1[i] == 0)
            {
                k++;
                ans.push_back(v1[i]);
                i++;
            }
            else
            {
                if (k >= v1[i])
                {
                    ans.push_back(v1[i]);
                    i++;
                }
                else
                {
                    fault = true;
                    break;
                }
            }
        }
        while (j < m)
        {
            if (v2[j] == 0)
            {
                k++;
                ans.push_back(v2[j]);
                j++;
            }
            else
            {
                if (k >= v2[j])
                {
                    ans.push_back(v2[j]);
                    j++;
                }
                else
                {
                    fault = true;
                    break;
                }
            }
        }
        if (fault)
        {
            cout << -1 << endl;
        }
        else
        {
            for (auto &val : ans)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}