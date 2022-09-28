#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        m[x]++;
    }
    int one=0;
    for(auto &val:m)
    {
        if(val.second == 1)
        {
            one++;
        }
    }
    cout<<one/2+one%2<<endl;
    }
    return 0;
}