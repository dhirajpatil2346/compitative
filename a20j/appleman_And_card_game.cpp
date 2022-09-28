#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> m;
    for(auto &val:s){m[val]++;}
    int j = k;
    long long p = 0;
    priority_queue<int>pq;
    for(auto &val:m)
    {
        pq.push(val.second);
    }
    while(j!=0)
    {
        int c = min(j, pq.top());
        // cout<<j<<"  "<<c<<endl;
        p+=c*1ll*c;
        j-=c;
        pq.pop();
    }
    cout<<p<<endl;
    return 0;
}