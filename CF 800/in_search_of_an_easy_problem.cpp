#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i]== 1){
            cout<<"HARD"<<endl;
            ans=false;
            break;
        }
    }
    if(ans!=false){
        cout<<"EASY"<<endl;
    }
    return 0;
}