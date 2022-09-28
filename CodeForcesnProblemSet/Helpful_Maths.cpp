#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    // cout<<s<<endl;
    // cout<<s.length()<<endl;
    vector<int> v;
    for (int i=0; i < s.length();i=i+2)
    {
        // cout<<i<<endl;
        v.push_back(s[i]-'0');
        // i=i+2;
    }
    sort(v.begin(),v.end());
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<"  ";
    // }
    for(auto it=v.begin();it != v.end(); ++it){
        if(it == v.end()-1){
            cout<<(*(v.end()-1));
        }
        else{
            cout<<(*it)<<"+";
        }
    }
    return 0;
}