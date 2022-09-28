#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int N=n;
    string s = to_string(n);
    while(true){
        N++;
        // cout<<N<<endl;
        string s = to_string(N);
        unordered_set<char> dp;
        for (int i = 0; i < s.length(); i++)
        {
            dp.insert(s[i]);
        }
        if(dp.size() == s.length())
        {
            cout<<N;
            return 0;
        }
        else{}
        
    }
    return 0;
}