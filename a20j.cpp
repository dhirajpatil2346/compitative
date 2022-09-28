#include <bits/stdc++.h>
 
using namespace std;
 
int main()
 
{
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

    int m,n;
    cin>>m>>n;
    string s="";
    int mini = min(m,n);
    string start="";
    if(m>=n)
    {
        start="BG";
    }
    else
    {
        start="GB";
    }
    m-=mini;
    n-=mini;
    while(mini--)
    {
        s+=start;
    }
    while(m--)
        {
            s+="B";
        }
        while(n--)
        {
            s+="G";
        }
        cout<<s<<endl;
    return 0;
}