#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int y=0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if(s=="++X" || s=="X++"){
            y++;
        }
        else{
            y--;
        }
    }
    cout<<y;
    return 0;
}