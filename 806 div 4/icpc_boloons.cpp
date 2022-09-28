#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int len;    
        cin>>len;
        string s;
        cin>>s;
        unordered_set<char>us;
        for(auto &val:s)
        {
            us.insert(val);
        }
        cout<<2*us.size()+(len-us.size())<<endl;
    }
    return 0;
}