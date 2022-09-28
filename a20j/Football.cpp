#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,int> m;
    while(n--){
        string s;
        cin>>s;
        if(m.count(s)>0){
            m[s]=m[s]+1;
        }
        else{
            m[s]=1;
        }
    }
    int max=INT_MIN;
    string l;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if(it->second>max)
        {
            max=it->second;
            l=it->first;
        }
    }
    cout<<l;
    return 0;
}