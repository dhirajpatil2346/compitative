#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = i ; j <= n ; j++)
        {
            int k = pow(i,2)+pow(j,2);
            int nn =  sqrt(k);
            if(nn<=n && nn*nn == k){
                // cout<<i<<j<<nn<<endl;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}