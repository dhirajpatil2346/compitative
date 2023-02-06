#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i]=i+1;
    }
    int ans = 0;
    do
    {
        int diff = INT_MAX;
        /*
        for (int i = 0; i < n; i++)
        {
             cout<<v[i]<<" ";
        }
        */
        for (int i = 0; i < n-1; i++)
        {
            diff  =min(diff, abs(v[i]-v[i+1]));
        }
        ans  = max(ans , diff);
        
        
    } while (next_permutation(v.begin(), v.end()));
    cout<<ans<<endl;
    return 0;
}