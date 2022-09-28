#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<char> v;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='1'){
                v.push_back(s[i]);
            }
        }
        if(v.size()%2==0){
            cout<<"NET"<<endl;
        }
        else{
            cout<<"DA"<<endl;
        }
        //000011111`
    }
    return 0;
}