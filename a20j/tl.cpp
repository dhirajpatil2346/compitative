#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> c(n), ic(k);
    for(auto &val:c)
    {
        cin>>val;
    }
    for(auto &val:ic)
    {
        cin>>val;
    }
    sort(c.begin(),c.end());
    sort(ic.begin(), ic.end());
    int cm=c[n-1];
    for(auto &val:c)
    {
        // cout<<val+val/2<<"  "<<cm<<"    "<<ic[0]<<endl;
                if(cm<=val+val/2 && ic[0]>val)
        {
            cout<<val<<endl;
            break;
        }
    }
    return 0;
}