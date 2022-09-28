#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2)
        {
            for (int i = 0; i < n; i++)
            {
                int k;
                cin>>k;
            }
            
            cout<<-1<<endl;
        }
        else
        {
            int pos=0,neg=0;
            int req=n/2;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin>>x;
                if(x<0)
                {
                    neg++;
                }
                else
                {
                    pos++;
                }
            }
            cout<<abs(neg-pos)/2<<endl;

        }
    }
    return 0;
}