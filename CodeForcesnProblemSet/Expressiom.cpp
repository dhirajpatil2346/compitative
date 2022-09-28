/*
1+2*3=7
1*(2+3)=5
1*2*3=6
(1+2)*3=9
1+2+3=4;
1*2+3=5;
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int max=0;
    int x, y, z, l,s,m;
    x = a +(b*c);
    if(x>=max){
        max=x;
    }
    y=a*(b+c);
    if(y>=max){
        max=y;
    }
    z=a*b*c;
    if(z>=max){
        max=z;
    }
    l = (a+b)*c;
    if(l>=max){
        max=l;
    }
    s=a+b+c;
    if(s>=max){
        max=s;
    }
    m=a*b+c;
    if(m>=max){
        max=m;
    }
    cout<<max;
    return 0;
}