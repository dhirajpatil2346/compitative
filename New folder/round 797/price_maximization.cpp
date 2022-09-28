#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int final = 0;
        int n, k;
        cin >> n >> k;
        vector<int> v1(n);
        vector<vector<int>> v2(k);
        for (auto &val : v1)
        {
            cin >> val; 
            v2[val % k].push_back(val);
            final += val / k;
        }
        if (!(k % 2))
        {
            for (int i = 1; i <= k / 2; i++)
            {
                final += min(v2[i].size(), v2[k - i].size());
            }
        }
        else
        {
            for (int i = 1; i < k / 2; i++)
            {
                final += min(v2[i].size(), v2[k - i].size());
            }
        }
        int id = 0;
        
        for(auto &val:v2)
        {
            cout<<id<<" ";
            for(auto v:val)
            {
                cout<<v<<" ";
            }
            id++;
            cout<<endl;
        }
        
        if ((v2[0].size()) % 2 == 1)
        {
            final++;
        }
        cout << final << endl;
    }
    return 0;
}