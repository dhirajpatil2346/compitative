#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int maxi = max(a, max(b,c));
        if(maxi==a)
        {
            cout<<"Alice"<<endl;
        }
        else if(maxi==b)
        {
            cout<<"Bob"<<endl;
        }
        else
        {
            cout<<"Charlie"<<endl;
        }
    }
    return 0;
}