#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        multiset<int> s;
        for(int  i = 0 ; i < a ;i++)
        {
            int x;
            cin>>x;
            s.insert(x);
        }
        while(c--)
        {
            auto it = s.begin();
            int z = *it ^ b;
            s.erase(it);
            s.insert(z);
        }
        for(auto &val:s)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}