#include<bits/stdc++.h>
using namespace std;

int solution(int c, int j, int p)
{
    if(c==j || j==0)
    {
       return 0;
    }
    else
    {
        int first=0,second=0,pl=p-1;
        first=min(c/p, j);
        j-=first;
        if(j%pl==0)
        {
            second=j/pl;
        }
        else
        {
            second=j/pl+1;
        }
        return first-second;           
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int c,j,p;
    cin>>c>>j>>p;
    cout<<solution(c,j,p)<<endl;
    }
    return 0;
}