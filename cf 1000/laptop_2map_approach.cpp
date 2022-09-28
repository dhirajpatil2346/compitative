#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int, int> m1,m2;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        m1[x]=y;
        m2[y]=x;
    }
    bool got=true;
    map<int,int> :: iterator it1,it2;
    for(it1=m1.begin(), it2=m2.begin(); it1!=m1.end(), it2!=m2.end();it1++,it2++)
    {
        if((it1->first!=it2->second) || (it1->second !=it2->first))
        {
            got=false;
            break;
        }
    }
    if(got)
    {
        cout<<"Poor Alex"<<endl;
    }
    else
    {
        cout<<"Happy Alex"<<endl;
    }
    return 0;
}