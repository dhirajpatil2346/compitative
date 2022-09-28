#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    s=to_string(n);
    vector<int> v;
    v={4, 7, 47, 74, 444, 447, 474, 777, 747, 477};
    if(n%4 == 0 || n%7 ==0)
    {
    cout<<"YES";
    return 0;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if(n % v[i] == 0)
        {
            cout<<"YES";
            return 0;
        }
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        
        if(s[i] !='4' && s[i] != '7')
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    
    return 0;
}