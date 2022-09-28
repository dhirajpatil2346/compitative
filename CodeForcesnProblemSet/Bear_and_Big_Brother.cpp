#include<bits/stdc++.h>
using namespace std;

int main(){
    int l,b;
    cin>>l>>b;
    int y=0;
    while(true){
        if(l>b){
            cout<<y;
            return 0;
        }
        y++;
        l=l*3;
        b=b*2;
    }
    return 0;
}