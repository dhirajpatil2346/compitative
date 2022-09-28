#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        for (int j = 0,k=1;  j< x; j++)
        {
            cout<<k<<" ";
            k+=2;
        }
        cout<<endl;
        
    }
    
    return 0;
}