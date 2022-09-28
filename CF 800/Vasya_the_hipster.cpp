#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    if(m>n){
        cout<<n<<" "<<(m-n)/2;
    }
    else{
        cout<<m<<" "<<(n-m)/2;
    }
    return 0;
}