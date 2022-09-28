#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    unordered_set<int> us;
    vector<int> v(n);
    for(auto &val:v)
    {
        cin>>val;
        us.insert(val);
    }
    if(us.size()==1)
    {
        cout<<1<<endl;
    }
    else if(us.size()!=1 && n==k)
    {
        cout<<-1<<endl;
    }
    int key = v[n-1];
    vector<int> vn;
    int i = n-1;
    while(i>=0 && v[i]==key)
    {
        vn.push_back(key);
    }
    return 0;
}