#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int mini = max(a, c);
        int maxi = b;
        if(mini<=maxi)
        {
            cout<<"YES"<<endl;
            
            
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}