#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if(n<m)
        {
            cout<<"REPAIR"<<endl;
        }
        else if(n>m)
        {
            cout<<"NEW PHONE"<<endl;
        }
        else
        {
            cout<<"ANY"<<endl;
        }
    }
    return 0;
}