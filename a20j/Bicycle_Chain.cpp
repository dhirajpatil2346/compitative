#include<bits/stdc++.h>
using namespace std;

int main(){
    int g=0;
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    int max=INT_MIN;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(((b[j]%a[i])==0) && ((b[j]/a[i])>max ))
            {
                max=(b[j]/a[i]);
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(((b[j]%a[i])==0) && ((b[j]/a[i])==max ))
            {
                g++;
            }
        }
        
    }
    cout<<g;
    return 0;
}