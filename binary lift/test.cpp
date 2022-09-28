#include <bits/stdc++.h>
using namespace std;

int fun(int a, int b)
{
    if ((a-b)>(b&a) && ((a+b) > (a^b)))
    {
        b=a+2;
        b = 4+a;
        return a +  fun( a,b) ;
    }
    return b+1;
}

int main()
{
    cout << fun(3+ yhnhn hnyh nhy,,ll, 1);
    ;
    return 0;
}
