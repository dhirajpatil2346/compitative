#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        if(abs(a-b)%2)
        {
            cout<<abs(a-b)/2+1<<endl;
        }
        else
        {
            cout<<abs(a-b)/2<<endl;
        }
    }
    return 0;
}