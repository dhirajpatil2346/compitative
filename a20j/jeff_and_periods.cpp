#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[v[i]].push_back(i);
    }
    bool failed = false;
    map<int, int>f;
    for(auto it = m.begin() ; it != m.end() ; it++)
    {
        failed=false;
        if(it->second.size() > 1)
        {
            int diff = it->second[1]-it->second[0];
            for (int i = 0; i < it->second.size() - 1; i++)
            {
                int curr = it->second[i+1]-it->second[i];
                if(curr!=diff)
                {
                    failed = true;
                    break;
                }
            }
            if(!failed)
            {
                f[it->first]= diff;
                // cout<<it->first<<" "<<diff<<endl;
            }
        }
        else
        {
            f[it->first]= 0;
            // cout<<it->first<<" "<<0<<endl;
        }
    }
    cout<<f.size()<<endl;
    for(auto &val : f)
    {
        cout<<val.first<<" "<<f[val.first]<<endl;
    }
    return 0;
}