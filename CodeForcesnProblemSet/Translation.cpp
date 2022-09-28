#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,m;
    cin>>s>>m;
    for (int i = 0,j=s.length()-1; i < s.length(), j>=0; i++,j--)
    {
        if(s[i] != m[j])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}