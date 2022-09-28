#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int inc=a;
    int cnt=1;
    while(a%10 != 0 && a%10 != b){
        cnt++;
        a+=inc;
    }
    cout<<cnt;
    return 0;
}