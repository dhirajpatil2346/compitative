#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int Chris=0, Mishka=0;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(n>m)
        {
            Mishka++;
        }
        else if(m>n)
        {
            Chris++;
        }
    }
    if(Mishka>Chris)
    {
        cout<<"Mishka"<<endl;
    }
    else if(Chris>Mishka)
    {
        cout<<"Chris"<<endl;
    }
    else{
        cout<<"Friendship is magic!^^"<<endl;
    }
    return 0;
}