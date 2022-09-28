#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
        }
        else if(n==2)
        {
            cout<<"23"<<endl;
        }
        else
        {
            string s="";
            if(((n-1)*2)%3==0)
            {
                for(int i = 0 ; i<n -2;i++)
                {
                    s+='2';
                }
                s+="43";
            }
            else
            {
                for(int i = 0 ;i< n - 1;i++)
                {
                    s+='2';
                }
                s+='3';
            }
            cout<<s<<endl;
        }
    }
    return 0;
}