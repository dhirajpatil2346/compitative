#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &val:v){cin>>val;}
    sort(v.begin(), v.end());
    int a = v[n-1],b=v[n-2],c=v[n-3];
    if( b+c>a)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}