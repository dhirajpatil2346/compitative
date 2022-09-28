#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int one=0,two=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1'){
            ++one;
        }
        else{
            ++two;
        }
    }
    if(one>two){
        cout<<one-two;
    }
    else{
        cout<<two-one;
    }
    return 0;
}