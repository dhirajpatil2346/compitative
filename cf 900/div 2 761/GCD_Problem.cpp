#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n>=6){
        if(n%2==0)
        {
        cout<<(n-1)/2<<" "<<n/2<<" "<<1<<endl;
        }
        else{
            cout<<n/2-2<<" "<<n/2+2<<" "<<1<<endl;
        }
        }
        else{
            if(n%2!=0)
            {
                cout<<n/2<<" "<<n/2<<" "<<1<<endl;
            }
            else{
                cout<<n/2-1<<" "<<2<<" "<<1<<endl;
            }
        }
    }
    return 0;
}