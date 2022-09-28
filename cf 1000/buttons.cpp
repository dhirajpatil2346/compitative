#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ch=0,l=n,ans=0;
    while(l--)
    {
        ans+=l*(ch+1);
        ch++;
    }
    cout<<ans+n<<endl;
    return 0;
}