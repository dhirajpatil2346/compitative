#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    v[0]=0;
    for(int i = 1 ; i<=n;i++)
    {
        cin>>v[i];
    }
    while(k--)
    {
        int damage=0;
        int x ,y;
        cin>>x>>y;
        if(y>=x)
        {
            for (int i = x; i <= y-1; i++)
            {
                if(v[i]<=v[i+1]){continue;}
                damage+=v[i]-v[i+1];
               
            }
        }
        else
        {
            for(int i = x ; i > y ; i--)
            {
                if(v[i-1]>=v[i]){continue;}
                damage+=v[i]-v[i-1];
                // cout<<i<<" "<<damage<<endl;
            }
        }
        cout<<damage<<endl;
    }
    return 0;
}