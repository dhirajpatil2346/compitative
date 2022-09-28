#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="I hate",m="I love";
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        if(i%2==0){
            if(i!=n)
                cout<<m<<" that ";
            else
                cout<<m<<" it";
        }
        else{
            if(i!=n)
                cout<<s<<" that ";
            else 
                cout<<s<<" it ";
        }
    }
    return 0;
}