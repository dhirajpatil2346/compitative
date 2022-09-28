#include<bits/stdc++.h>
using namespace std;

int main(){
    // sum is odd -- Alice
    //  else -- Bob
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int j,k;
        cin>>j>>k;
        if((j+k)%2==0){
            cout<<"Bob"<<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }
    }
    
    return 0;
}