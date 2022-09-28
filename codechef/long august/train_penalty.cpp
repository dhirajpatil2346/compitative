#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n-1);
        int maxi = INT_MIN;
        for (int i = 0; i < n-1; i++)
        {
            cin>>v[i];
            maxi = max(maxi, v[i]);
        }
        int p=0;
        for(int i = 0 ; i < n-2 ; i++)
        {
            if(v[i]>v[i+1])
            {
                p+=(v[i]-v[i+1]);
            }
        }
        // cout<<p<<"  "<<maxi<<endl;
        int ans = accumulate(v.begin(), v.end(), maxi);
        cout<<ans<<endl;
    }
    return 0;
}