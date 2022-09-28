#include<bits/stdc++.h>
using namespace std;

int main(){
    int s,n;
    cin>>s>>n;
    pair<int,int> m[n];
    for (int i = 0; i < n; i++)
    {
        int xi,yi;
        cin>>xi>>yi;
        m[i]={xi,yi};
    }
    sort(m, m+n);
    for (auto it = m; it != m+n; it++)
    {
        
        if(s<=it->first)
        {
            cout<<"NO";
            return 0;
        }
        else{
            // s-=it->first;
            s+=it->second;
        }
    }
    
    cout<<"YES";
    return 0;
}