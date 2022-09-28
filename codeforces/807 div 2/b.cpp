#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0 ; i < n; i++)
        {
            cin>>v[i];
        }
        int sum = accumulate(v.begin(), v.end(),0);
        sum-=v[n-1];
        if(sum==0)
        {
            ans=0;
        }
        else
        {
            int j = 0;
            while(v[j]==0)
            {
                j++;
            }
            for(int i = j ; i < n-1 ; i++)
            {
                ans+=max(1, v[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}