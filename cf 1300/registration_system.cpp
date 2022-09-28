#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<string,int> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if(m[s]==0)
        {
            cout<<"OK"<<endl;
            m[s]++;
        }
        else
        {
            cout<<s<<(m[s]++)<<endl;
        }
    }
    
    return 0;
}