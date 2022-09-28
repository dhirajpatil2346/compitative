#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool got=false;
    for (int i = 0; i <= n-3; i++)
    {
        if(s[i]=='0' && s[i+1]=='1' && s[i+2]=='0')
        {
            got=true;
        }
    }
    if(got)
    {
        cout<<1<<endl;
    }
    else if(s[0]=='0' && s[s.length()-1] == '1')
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<2<<endl;
    }
    }
    return 0;
}