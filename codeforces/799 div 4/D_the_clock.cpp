#include<bits/stdc++.h>
using namespace std;

bool isP(string a, string b)
{
    return ((a[1]==b[0])&&(a[0]==b[1]));
}

int main(){
    string s;
    int inc;
    cin>>s;
    cin>>inc;
    int n1 = (s[0]-'0')*10 + (s[1]-'0');
    int n2 = (s[3]-'0')*10 + (s[4]-'0');
    int curr=n1*60+n2;
    int f=0;
    while(curr<=1440)
    {
        string a="",b="";
        int h = 1440/60,m=1440%60;
        if(h<10)
        {
            a+='0';
            a+=(h+'0');
        }
        else
        {
            a=to_string(h);
        }
        if(m<10)
        {
            b+='0';
            b+=(m+'0');
        }
        else
        {
            b=to_string(m);
        }
        if(isP(a,b))
        {
            f++;
        }
        curr+=inc;

    }
    cout<<f<<endl;
    return 0;
}