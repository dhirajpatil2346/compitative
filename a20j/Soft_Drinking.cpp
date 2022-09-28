#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int f_total_ml=((k*l/nl)/n), slice=c*d/n,salt=(p/np)/n;
    if(f_total_ml<=slice && f_total_ml<=salt)
    {
        cout<<f_total_ml;
    }
    else if(f_total_ml>=slice && salt>=slice)
    {
        cout<<slice;
    }
    else{
        cout<<salt;
    }
    return 0;
}