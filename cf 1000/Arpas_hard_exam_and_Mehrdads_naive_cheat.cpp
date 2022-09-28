#include <bits/stdc++.h>
using namespace std;

int main()
{
    int curr = 8;
    long long n;
    cin >> n;
    if(n==0)
    {
        cout<<1<<endl;
    }
    else if(n==1)
{
    cout<<8<<endl;
}
else if(n==2)
{
    cout<<4<<endl;
}
else if(n==3)
{
    cout<<2<<endl;
}
else
{
    if(n%4==0)
    {
        cout<<6<<endl;
    }
    else if(n%4==1)
    {
        cout<<8<<endl;
    }
    else if(n%4==2)
    {
        cout<<4<<endl;
    }
    else
    {
        cout<<2<<endl;
    }
}
    return 0;
}



/*
1 8
2 4
3 2 1
4 6 0
5 8 1
6 4 2
7 2 3
8 6 0
9 8  1
10 4 2
11 2 3



*/