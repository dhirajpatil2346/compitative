#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        long long int x;
        cin>>x;
        while(x%2==0){
            x=x/2;
        }
        if(x==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"Yes"<<endl;        }
    }
    
    return 0;
}