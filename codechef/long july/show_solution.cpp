#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        long long r = 0;
        int m  = c / a;
        if(m>=a)
        {
            r = a * pow(b,2);
        }
        else
        {
            r = (c/a)*(pow(b,2)) + pow(c%b, 2);
        }
        cout<<r<<endl;
    }
    return 0;
}