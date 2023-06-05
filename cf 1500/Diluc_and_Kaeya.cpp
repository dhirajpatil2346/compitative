#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        string s;
        cin>>n>>s;
        map<char,int> m;
        m['D']=0, m['K']=0;
        for(auto &val:s) {m[val]++;cout<<__gcd(m['D'], m['K'])<<" ";}
        cout<<endl;
    }
    return 0;
}