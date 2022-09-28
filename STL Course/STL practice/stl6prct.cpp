#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> mp;
    mp[2] = 99;
    mp[1] = 66;
    mp[11] = 55;
    mp[55] = 23;
    mp[66] = 14;
    // map<int,int> ::iterator it=mp.begin();
    // while(!mp.empty()){
    //     cout<<mp.begin()->first<<"  "<<mp.begin()->second<<endl;
    //     mp.erase(mp.begin());
    // }
    mp.insert(pair<int, int>(115, 131));
    map<int, int> kk;
    kk.insert(mp.begin(), mp.find(55));
    for (auto &v : kk)
    {
        cout << v.first << "    " << v.second << endl;
    }
    return 0;
}