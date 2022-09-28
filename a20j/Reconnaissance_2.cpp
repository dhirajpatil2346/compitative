#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        b[i]=x;
    }
    sort(b,b+n);
    
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    
    int p1=0,p2=1;
    int min= b[1]-b[0];
    for (int i = 1; i < n-1; i++)
    {
        if((b[i+1]-b[i])<min)
        {
            min=b[i+1]-b[i];
            cout<<min<<endl;
            p1=i,p2=i+1;
        }
    }
    cout<<p1<<" "<<p2<<endl;
    int req1=b[p1], req2=b[p2];
    cout<<" req are "<<req1<<"   "<<req2<<endl;
    bool p1g=true,p2g=true;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==req1 && p1g){
            p1=i+1;
            p1g=false;
        }
        else if(a[i]==req2 && p2g){
            p2=i+1;
            p2g=false;
        }
    }
    cout<<p1<<' '<<p2;
    return 0;
}