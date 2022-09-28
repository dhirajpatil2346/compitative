#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int nl=0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '4' || s[i] == '7'){
            nl++;
        }
    }
    unordered_set<char> us;
    string m=to_string(nl);
    for (int i = 0; i < m.length(); i++)
    {
        if(m[i] == '4' || m[i] == '7'){
            us.insert(m[i]);
        }
    }
    if(!us.empty()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}