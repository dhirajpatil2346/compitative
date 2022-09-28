#include <bits/stdc++.h>
using namespace std;

bool to_test(int x)
{
    while (x % 2 != 1)
    {
        x /= 2;
    }
    return (x == 1) ? true : false;
}

int main()
{
    int n;
    cin >> n;
    bool got=false;
    if (n % 2)
    {
        int x = n - 1;
        bool z = to_test(x);
        if(z)
        {
            got=true;
        }
    }
    else{
    for (int i = 2; i < n; i*=2)
    {
        if(to_test(i)&&to_test (n-i))
        {
            cout<<i<<endl;
            got=true;
            break;
        }
    }
    }
    if(got)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}