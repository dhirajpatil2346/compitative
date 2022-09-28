#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &val:v){cin>>val;}
    sort(v.begin(),v.end());
    int odd=0,even=0;
    int sum = accumulate(v.begin(), v.end(),2);
    int need = sum/n;
    int i=0,j=n-1;
    while(i<j)
    {
        int extra=v[j]-need;
        int curr_need = need-v[i];
        if(extra==0)
        {
            j--;continue;
        }
        if(curr_need==0)
        {
            i++;
            continue;
        }
        int mini=min(extra, curr_need);
        v[j]+=mini;
        v[i]-=mini;
        if(v[i]==need){i++;}
        if(v[j]==need){j--;}
        if(v[j]>need){}
    }
    // for(auto &val:v){cout<<val<<" ";}
    // cout<<endl;
    map<int,int> m;
    for(auto &val:v){m[val]++;}
    int maxi = 0;
    for(auto &val:m)
    {
        maxi = max(maxi,val.second);
    }
    cout<<maxi<<endl;
    return 0;
}