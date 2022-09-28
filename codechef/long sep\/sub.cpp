#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        long long maxi = *max_element(v.begin(),v.end());
        long long mini= *min_element(v.begin(),v.end());
        if(mini<0)
        {
            cout<<mini*maxi<<" "<<max(maxi*maxi, mini*mini)<<endl;
        }
        else{
            cout<<mini*mini<<" "<<maxi*maxi<<endl;
        }
    }
    return 0;
}