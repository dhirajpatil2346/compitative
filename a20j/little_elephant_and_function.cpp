#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

void eleswap(int arr[], int n)
{
    for (int i = n-1; i > 0; i--)
    {
        int temp=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=temp;
    }
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=i+1;
    }
    // int n=sizeof(arr)/sizeof(arr[0]);
    eleswap(arr,  n);
    printArray(arr,n);
    return 0;
}