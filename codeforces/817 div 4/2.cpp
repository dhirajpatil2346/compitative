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
        string s, k;
        cin >> s >> k;
        bool fault = false;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='B' && k[i]=='G'){continue;}
            if(s[i]=='G' && k[i]=='B'){continue;}
            if (s[i] != k[i] )
            {
                fault = true;
                break;
            }
        }
        if(fault)
        {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}