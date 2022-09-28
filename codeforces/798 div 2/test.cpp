#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<char>v;
    string s;
    cin>>s;
    for(auto &val:s){v.push_back(val);}
    for(auto &val:v){cout<<val;}
    cout<<endl;
    sort(v.begin(),v.end());
    for(auto &val:v){cout<<val;}
    return 0;
}