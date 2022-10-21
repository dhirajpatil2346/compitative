#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll m = 1e9 + 7;

ll bin(ll n, ll k)
{
    if (k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return n % m;
    }
    ll res = bin(n, k / 2);
    if (k % 2)
    {
        return ((n % m) * (res % m) * (res % m)) % m;
    }
    return (res % m) * (res % m) % m;
}

int main()
{
    cout<<(bin(5,8)*bin(4,7))%m<<endl;
   
}

/*
9
2 - 7 - 2
2 - 5 - 4
2 - 3 - 8
2 - 1 - 16
1 - 1 - 16

9
3 - 6 - 3
3 - 3 - 9
3 - 0 - 27

7
2 - 5 - 2
2 - 3 - 4
2 - 1 - 8
1 - 1 - 8

7
4 - 3 - 4
3 - 0 - 12
10
 2 2 2 2 2 32
 3 3 3 1 27

13
64 - 2

11 - 5 6 -30
11 - 2 2 2 2 2 1 - 32
11 - 3 3 3 2 - 54
11 - 4 4 3 - 48
11 - 5 5 1 - 25

15
3 3 3 3 3 3 - 729
2 2 2 2 2 2 3 - 192
4 4 4 3 - 192
5 5 5 - 625
6 6 3 - 108
7 8 - 56

8 - 2 2 2 2 - 16
8 - 3 3 2 - 18


*/