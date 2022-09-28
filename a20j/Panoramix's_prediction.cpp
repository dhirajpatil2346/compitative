#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int a,b;
    cin>>a>>b;
    int m = find(v.begin(),v.end(),b)-v.begin();
    int n = find(v.begin(),v.end(),a)-v.begin();
    // cout<<m<<"  "<<n<<endl;
    if(a==47){
        cout<<"NO"<<endl;
        return 0;
    }
    if((m-n) == 1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}