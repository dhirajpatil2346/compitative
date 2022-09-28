#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            cout<<2<<endl;
        }
        else if(x%3)
        {
            cout<<x/3+1<<endl;
        }
        else
        {
            cout<<x/3<<endl;
        }
    }
    return 0;
}