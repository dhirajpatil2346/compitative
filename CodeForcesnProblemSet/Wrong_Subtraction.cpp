#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    for (int i = 0; i < n; i++)
    {
        if(m%10 != 0){
            m--;
        }
        else{
            m=m/10;
        }
    }
    cout<<m;
    return 0;
}