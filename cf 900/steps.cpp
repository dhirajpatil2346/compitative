#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int v[n];
    cin>>v[0];
    int max=0, curr=1;
    if(n>1){
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        if(v[i]>=v[i-1]){
            curr++;
            if(curr>=max){
                max=curr;
            }
        }
        else{
            if(curr>=max){
                max=curr;
            }
            curr=1;
        }
    }}
    else{
        max=1;
    }
    cout<<max;
    return 0;
}