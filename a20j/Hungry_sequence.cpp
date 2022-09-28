#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    arr[0] = 2 ;
    int start = 3;
    for (int i = 1; i < n; i++)
    {
        arr[i]=start;
        start+=2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}