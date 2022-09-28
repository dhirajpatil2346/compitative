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
        double d = (double)b / (double)c;
        cout<<d<<"  "<<a<<endl;
        if(c<a)
        {
            cout<<-1<<" "<<b<<endl;
        }
        else if(d==a)
        {
            cout<<-1<<" "<<-1<<endl;
        }
        else if(d<a)
        {
            cout<<1<<" "<<b<<endl;
        }
        else if(d>a)
        {
            cout<<1<<" "<<-1<<endl;
        }
        else 
        {
            cout<<-1<<" "<<b<<endl;
        }
    }
    return 0;
}