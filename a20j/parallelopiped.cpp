#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
    lb=2
    bh=5
    lh=1
    b=2h
    2h^2=5
    h=sqrt(5/2)
    l=1/h
    b=2/l

    lb=i
    lh=j
    bh=k

    b=ih/j

    ih^2/j=k --> h =sqrt(jk/i)
    l=j/h
    b=i/l
    */
    double i,j,k;
    cin>>i>>j>>k;
    double h,l,b;
    h=sqrt((j*k)/i);
    l=j/h;
    b=i/l;
    cout<<4*(l+b+h);
    return 0;
}