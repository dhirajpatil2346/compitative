#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int, int> m;
    while(n--)
    {
        int x;
        cin>>x;
        if(m.count(x)==0)
        {
            m[x]=1;
        }
        else{
            m[x]++;
        }
    }
    cout<<m.size()<<endl;
    for (auto &i:m)
    {
        cout<<i.first<<' '<<i.second<<endl;
    }
    
    
    return 0;
}