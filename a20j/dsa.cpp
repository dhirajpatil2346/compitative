#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    int arr[n];
    int t=n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Position"<<"  "<<"Element"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<i+1<<"        "<<arr[i]<<endl;
    }
    cout<<"enter no. to search : ";
    int x;
    cin>>x;
    int pos=-1;
    for (int i = 0; i < n; i++)
    {
        if(x==arr[i]){
            pos=i+1;
            break;
        }
    }
    if(pos==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at position "<<pos<<endl;
    }
    return 0;
}