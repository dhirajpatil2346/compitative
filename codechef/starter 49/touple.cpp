#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        bool got=false;
        int a,b,c;
        cin>>a>>b>>c;
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                for(int k = 1 ; k <= 10 ; k++)
                {
                    if(min(i,j)==a && min(j,k)==b && min(i,k)==c)
                    {
                        got=true;
                        break;
                    }
                }
            }
        }
        if(got)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}