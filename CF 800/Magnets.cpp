#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<string> v;
    string y;
    cin>>y;
    v.push_back(y);
    int ans=1;
    for (int i = 1; i < t; i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
        if(v[i]!=v[i-1]){
            // cout<<i+1<<endl;
            ans++;
        }
    }
    /*
    for (int i = 1; i < t; i++)
    {
        // string s;
        // cin>>s;
        // v.push_back(s);
        if(v[i]!=v[i-1]){
            // cout<<i+1<<endl;
            ans++;
        }
    }
    // for (int i = 0; i < t; i++)
    // {
    //     cout<<v[i]<<endl;
    // }
    */
    cout<<ans;
    return 0;
}