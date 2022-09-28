#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,count=0;
    cin>>n;
    int arr[]={1,5,10,20,100};
    for (int i = 4; i >= 0; i--)
    {
        
        
        if (n<arr[i]){
            continue;
        }
        else {
        count = count + (n/arr[i]);
        n = n%arr[i];
        }
        // cout<<n<<endl;
        if(n==0){
            cout<<count;
            return 0;
        }
    }
    
    return 0;
}