#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int max=arr[0],min=arr[0];
    int amz=0;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max){
            max=arr[i];
            amz++;
        }
        if(arr[i]<min)
        {
            min=arr[i];
            amz++;
        }
    }
    cout<<amz;
    return 0;
}