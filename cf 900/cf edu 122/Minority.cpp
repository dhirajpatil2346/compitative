#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

    
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '0')
        {
            c0++;
        }
        else
        {
            c1++;
        }
    }
    if(c1==c0)
    {
        cout<<0<<endl;
    }
    else{
        cout<<min(c1,c0)<<endl;
    }
    }
    return 0;
}