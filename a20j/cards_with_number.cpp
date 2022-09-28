#include <bits/stdc++.h>
using namespace std;

int main()
{

    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
    vector<int> v(600000+5);
    int n;
    cin >> n;
    vector<vector<int>> m(5001);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> v[i];
        m[v[i]].push_back(i);
    }
    bool got=false;
    for(auto &val:m)
    {
        if(val.size()%2)
        {
            got=true;
            break;
        }
    }
    if(got){cout<<-1<<endl;}
    else
    {
        for(auto &val:m)
        {
            for (int i = 0; i < val.size(); i+=2)
            {
                cout<<val[i]<<" "<<val[i+1]<<endl;
            }
            
        }
    }
    
    return 0;
}