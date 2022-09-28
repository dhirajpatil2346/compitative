#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+m);
    // for (int i = 0; i < m; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int min=INT_MAX;
    if(m>n){
    for (int i =0; i<=m-n ; i++)
    {
        // cout<<arr[i+n-1]-arr[i]<<endl;
        if(arr[i+n-1]-arr[i]<min)
        {
            min=arr[i+n-1]-arr[i];
            // cout<<min<<endl;
        }
    }
    }
    else{
        min=arr[m-1]-arr[0];
    }
    cout<<min;
    return 0;
}