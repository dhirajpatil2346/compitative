#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int p=0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            if(x>1)
            {
                p++;
            }
        }
        if(p%2)
        {
            cout<<"Mike"<<endl;
        }
        else
        {
            cout<<"Joe"<<endl;
        }
    }    
    return 0;
}