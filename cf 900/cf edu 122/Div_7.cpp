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
    if (n % 7 == 0)
    {
        cout << n << endl;
    }
    else
    {
        int mod = n%7; // 2
        int last = n%10; // 3
        int req;
        if(last-mod>0 && (7-mod)+last < 10)
        {
            cout<<min(n+(7-mod), n-mod)<<endl;
        }
        else if(last-mod < 0)
        {
            cout<<n+(7-mod)<<endl;
        }
        else if((7-mod)+last > 10)
        {
            cout<<n-mod<<endl;
        }
    }
    }
    return 0;
}