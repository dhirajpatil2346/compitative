#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int m,n,k;
        cin>>m>>n>>k;
        n*=k;
        if(m%n)
        {
            cout<<m/n+1<<endl;
        }
        else
        {
            cout<<m/n<<endl;
        }
    }
    return 0;
}