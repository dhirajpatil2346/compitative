#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int len = s.length();
    bool zero = false;
    int ind =0;
    for (int i = 0; i < len; i++)
    {
        if(s[i]=='0')
        {
            zero=true;
            ind= i;
            break;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if(i!=ind)
        {
            cout<<s[i];
        }
    }
    
    return 0;
}