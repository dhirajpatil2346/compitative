#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int A;
    int D;
    for (int i = 0,h=0,v=0; i < n; i++)
    {
        // cout<<s[i]<<endl;
        if(s[i] == 'A'){
            h++;
        }
        else{
            v++;
        }
        A=h;
        D=v;
    }
    // cout<<A<<"  "<<D<<endl;
    if(A>D){
        cout<<"Anton";
    }
    else if(D>A){
        cout<<"Danik";
    }
    else{
        cout<<"Friendship";
    }
    return 0;
}