#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,count=0,s=0;
    cin>>n;
    // stack<int> s;
    while (n--)
    {
        int x;
        cin>>x;
        if(x==-1 && s==0)
        {
            count++;
        }
        else if(x==-1 && s>0)
        {
            s--;
        }
        else{
            s+=x;;
        }
    }
    cout<<count;
    return 0;
}