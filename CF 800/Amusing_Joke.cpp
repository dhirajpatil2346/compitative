#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c;
    cin>>a>>b>>c;
    vector<char> s1,s2;
    for (int i = 0; i < a.length(); i++)
    {
        s1.push_back(a[i]);
    }
    for (int i = 0; i < b.length(); i++)
    {
        s1.push_back(b[i]);
    }
    for (int i = 0; i < c.length(); i++)
    {
        s2.push_back(c[i]);
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}