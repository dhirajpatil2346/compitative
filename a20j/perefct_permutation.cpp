#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%2==0){
    int arr[n];
    int req=n;
    for (int i = 1; i <= n/2; i++)
    {
        int index=i-1;
        arr[index]=req;
        req--;
        arr[req]=i;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    }
    else{
        cout<<"-1"<<endl;
    }
    return 0;
}