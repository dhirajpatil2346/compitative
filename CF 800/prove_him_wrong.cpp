#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n>19)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            int curr=1;
            cout<<curr<<" ";
            for(int i = 1 ; i< n ; i++)
            {
                curr*=3;
                cout<<curr<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}