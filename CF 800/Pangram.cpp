#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_set<char> s;
    for (int i = 0; i < n; i++)
    {
        char y;
        cin>>y;
        if(y<96){
            y=y+32;
        }
        s.insert(y);
    }
    // cout<<s.size()<<endl;
    if(s.size()==26){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}