#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        m[x]=y;
    }
    int arr[n][2];
    int i=0;
    for(auto &val:m)
    {
        arr[i][0]=val.first, arr[i][1]=val.second;
        i++;
    }
    bool got=true;
    for (i = 0; i < n-1; i++)
    {
        if(((arr[i][0]>arr[i+1][0]) &&( arr[i][1]>arr[i+1][1])) || ((arr[i][0]<arr[i+1][0]) &&( arr[i][1]<arr[i+1][1])))
        {
            got=false;
            break;
        }
    }
    
    if(got)
    {
        cout<<"Happy Alex"<<endl;
    }
    else
    {
        cout<<"Poor Alex"<<endl;
    }
    return 0;
}