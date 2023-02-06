#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int ans=0;
        while(n--)
        {
            int x;
            cin>>x;
            ans|=x;
        }
        cout << ans << endl;
    }
    return 0;
}