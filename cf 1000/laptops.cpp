#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][2];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    bool got=true;
    for (int i = 0; i < n-1; i++)
    {
        if(((arr[i][0]>arr[i+1][0]) &&( arr[i][1]>arr[i+1][1])) || ((arr[i][0]<arr[i+1][0]) &&( arr[i][1]<arr[i+1][1])))
        {
            got=false;
            break;
        }
    }
    
    if(got)
    {
        cout<<"Happy Alex"<<endl;
    }
    else
    {
        cout<<"Poor Alex"<<endl;
    }
    return 0;
}