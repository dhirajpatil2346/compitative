#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,sum=0,count=0;
    cin>>n>>m;
    int min=240-m;
    int i = 5;
    while(true){
        if(sum>min){
            if(count<=n)
                cout<<count-1;
            else{
                cout<<n;
            }
            break;
        }
        else if(sum==min){
            if(count<=n)
                cout<<count;
            else{
                cout<<n;
            }
            break;
        }
        else{
            sum+=i;
            i+=5;
            count++;
        }
    }
    return 0;
}