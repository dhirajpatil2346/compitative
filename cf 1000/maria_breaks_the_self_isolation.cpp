#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        sort(v.begin(), v.end());
        int ans = n+1;
        bool got=false;
        for (int i = 0; i < n; i++)
        {
            if(v[i]<=i+1)
            {
                got=true;
                ans=i+2;
            }
        }
        if(got){
        cout << ans << endl;
        }
        else
        {
            cout<<1<<endl;
        }
    }
    return 0;
}