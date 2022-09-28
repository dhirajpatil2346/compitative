#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int t = k;
    vector<int> v(n + 1);
    map<pair<int, int>, int> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }cout<<"Proceed"<<endl;
    map<int, vector<int>> forw;
    map<int, vector<int>> back;
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        if (i < j)
        {
            forw[i].push_back(j);
        }
        else
        {
            back[i].push_back(j);
        }
    }
    for (auto &val : forw)
    {
        sort(val.second.begin(), val.second.end());
    }

    for (auto &val : back)
    {
        sort(val.second.begin(), val.second.end());
        reverse(val.second.begin(), val.second.end());
    }

    for (auto &val : forw)
    {
        int start = val.first;
        int end = val.second[val.second.size() - 1];
        for (int i = start; i < end; i++)
        {
            int d = 0;
            for (int j = i + 1; j <= end; j++)
            {
                if (val.second[j] >= val.second[j - 1])
                {
                    m[{i, j}] = d;

                    cout<<i<<","<<j<<""<<m[{i,j}]<<endl;
                }
                else
                {
                    d += abs(val.second[j] - val.second[j - 1]);
                    m[{i, j}] = d;
                    cout<<i<<","<<j<<""<<m[{i,j}]<<endl;
                }
            }
        }
    }
    for (auto &val : back)
    {
        int start = val.first;
        int end = val.second[val.second.size() - 1];
        for (int i = n; i > 1; i--)
        {
            int d = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (val.second[j] >= val.second[j + 1])
                {
                    m[{i, j}] = d;
                }
                else
                {
                    d += abs(val.second[j + 1] - val.second[j]);
                    m[{i, j}] = d;
                }
            }
        }
    }
    while(t--)
    {
        int i,j;
        cin>>i>>j;
        cout<<m[{i,j}]<<endl;
    }
    return 0;
}