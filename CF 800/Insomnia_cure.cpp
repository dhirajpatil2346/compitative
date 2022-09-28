#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;
    vector<int> v;
    for (int i = 1; i <= d; i++)
    {
        if((i>= k && i%k==0) 
        || (i>=l && i%l==0) 
        || (i>=m && i%m==0) 
        || (i>= n && i%n==0))
        {
            continue;
        }
        else{
            v.push_back(i);
        }
    }
    cout<<d-v.size();
    return 0;
}